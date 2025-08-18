/*7.Nested Structures and Arrays within Structures
Goal
Explore how to organize complex data using nested structures and how to embed arrays inside structures for buffer management.

Activity
Log Session a structure with another structure as a member.
Log Session an array of structures to hold multiple sensor values.
Include arrays within a structure to buffer a set of samples.
Model a protocol layer with header and payload sub-structures.
Tip: Use typedef to simplify nested structure declarations.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
struct st{
int x;
};
struct st1{
int y;
struct st v;
};


#define MAX_PAYLOAD_SIZE 256

typedef struct {
    uint8_t srcAddr;
    uint8_t destAddr;
    uint8_t type;
    uint16_t length;
} ProtocolHeader;

typedef struct {
    uint8_t data[MAX_PAYLOAD_SIZE];
} ProtocolPayload;

typedef struct {
    ProtocolHeader header;
    ProtocolPayload payload;
} ProtocolPacket;

int main() 
{
    struct st1 v2={1,{2}};
    printf("%d %d\n",v2.y,v2.v.x);
    ProtocolPacket* packet = (ProtocolPacket*)malloc(sizeof(ProtocolPacket));
    if (!packet) {
        printf("Allocation failed!\n");
        return -1;
    }

    packet->header.srcAddr = 0x01;
    packet->header.destAddr = 0x0A;
    packet->header.type = 0x02;
    packet->header.length = 5;

    const char* message = "Hello";
    memcpy(packet->payload.data, message, packet->header.length);

     printf("  Src:  0x%02X\n", packet->header.srcAddr);
    printf("  Dest: 0x%02X\n", packet->header.destAddr);
    printf("  Type: 0x%02X\n", packet->header.type);
    printf("  Length: %d\n", packet->header.length);
    printf("  Payload: ");
    for (int i = 0; i < packet->header.length; i++) {
        printf("%c", packet->payload.data[i]);
    }
    printf("\n");

    free(packet);
    return 0;
}
