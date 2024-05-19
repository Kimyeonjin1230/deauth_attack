# RadioTap Header? 
: 802.11 패킷을 송수신 할 때 도움되는 추가 정보를 담은 헤더. 리틀엔디언 방식. RadioTab 헤더에는 많은 정보가 있지만 중요한거 하나만 말해보자면 airodump-ng 에서 출력해주는 정보 중, Antenna Signal 즉, 안테나의 신호 세기인 dbm 정보가 담겨 있다.

lan 카드를 monitor mode로 바꿔준다.

`ifconfig <old interface> down`
`ip link set <old interface> name <new interface>` //정신없던 인터페이스에서 mon0라는 이름으로 바꿔주겠다.
`ifconfig <new interface> up`

ifconfig <interface> down
iwconfig <interface> mode monitor
ifconfig <interface> up



![스크린샷 2024-05-20 00-51-12](https://github.com/Kimyeonjin1230/deauth_attack/assets/114148238/88bd056d-9ae4-4c44-b9ba-46ff80d9261f)
