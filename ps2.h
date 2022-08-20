
#ifndef __PS2_H__
#define __PS2_H__
#include <stdbool.h>
#define PORT_KEY 0
#define PORT_MOUSE 1

#define CLOCK 0
#define DATA 1

typedef union sendbuffer {
	const uint8_t *chunky[64];
	uint8_t arbitrary[64];
} sendbuffer;

typedef struct ps2port
{
	uint8_t state;
	uint8_t port;
	uint8_t data;
	uint8_t sendbit;
	uint8_t recvbit;
	uint8_t parity;
	uint8_t sendingCustom;

	uint8_t recvstate;

	// byte number within current chunk
	uint8_t bytenum;

	uint8_t recvvalid;
	uint8_t recvout;
	uint8_t recverror;

	uint8_t lastByte;

	// ring buffer (pointers to chunks)
	uint8_t sendBuffStart;
	uint8_t sendBuffEnd;
	sendbuffer sendBuff;
	uint8_t recvBuff;
	uint8_t prevhid[8];

	// temporary buffer to hold a custom chunk
	// (i.e. one defined in RAM rather than code)
	uint8_t customChunk[8];
} ps2port;

extern __xdata ps2port keyboard;
extern __xdata ps2port mouse;

void SendHIDPS2(unsigned short length, unsigned char type, unsigned char __xdata *msgbuffer);

void OutPort(unsigned char port, unsigned char channel, bool val);

bool GetPort(unsigned char port, unsigned char channel);

void SendPS2(ps2port *port, const uint8_t *chunk);

#define S_INIT 0
#define S_IDLE 1
#define S_SEND_CLOCK_LOW 2
#define S_SEND_CLOCK_HIGH 3
#define S_RECEIVE_CLOCK_LOW 4
#define S_RECEIVE_CLOCK_HIGH 5
#define S_RECEIVE_ACK 6
#define S_PAUSE 9
#define S_INHIBIT 10
#define S_WAIT 11

#define R_IDLE 0
#define R_LEDS 1
#define R_REPEAT 2

void PS2ProcessPort(ps2port *port);
#endif