#ifndef B64_H
#define B64_H

#include <string.h>
#include <stdlib.h>

// isolates the nth block of 6 bits in x, starting from the right
#define NTH_BLOCK(x,n) (x >> (6*n)) & 0x3f


void encode(const char *src, char* dst, unsigned int length);
void decode(const char *src, char* dst);

#endif