#ifndef B64_H
#define B64_H

#include <string.h>
#include <stdlib.h>

void encode(const char *src, char* dst, unsigned int length);
void decode(const char *src, char* dst);

#endif