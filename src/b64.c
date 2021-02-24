#include "b64.h"

// the conversion table for base46 encoding/decoding
const char* b64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

// encodes a block 3 (or less) bytes from src, and writes
// the base64 encoded data in dst. If length > 3, the function
// will only encode 3 bytes of data
void encode(const byte* src, byte* dst, unsigned int length)
{
    int i, j, k, l;
    switch (length)
    {
    case 1:
        i = src[0]>>2;
        j = (src[0]&3) << 4;
        k = 64; l = 64;
        break;
    case 2:
        i = src[0]>>2;
        j = ((src[0]&3)<<4) + (src[1]>>4);
        k = (src[1] & 15)<<2;
        l = 64;
        break;
    default:
        i = src[0]>>2;
        j = ((src[0]&3)<<4) + (src[1]>>4);
        k = ((src[1] & 0xf) << 2) + (src[2]>>6 & 3);
        l = src[2] & 0x3f;
        break;
    }
    dst[0] = b64Table[i]; 
    dst[1] = b64Table[j];
    dst[2] = b64Table[k]; 
    dst[3] = b64Table[l];
}
// reads a 4-character long base64 encoded string src, and writes the
// decoded bytes in dst
void decode(const byte* src, byte* dst)
{

}