#ifndef B64_H
#define B64_H

#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;

void encode(const byte *src, byte* dst, unsigned int length);
int decode(const byte *src, byte* dst);

#endif