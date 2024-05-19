# Variables
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lpcap
TARGET = d_attack
SRCS = d_attack.c
OBJS = $(SRCS:.c=.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
