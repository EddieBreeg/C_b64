#include "b64.h"

// isolates the nth block of 6 bits in x, starting from the right
#define NTH_BLOCK(x,n) (x >> (6*n)) & 0x3f

// the conversion table for base46 encoding/decoding
const char* b64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// encodes a block 3 (or less) bytes from src, and writes
// the base64 encoded data in dst. If length > 3, the function
// will only encode 3 bytes of data
void encode(const char* src, char* dst, unsigned int length)
{
    if(length>=3)
    {
        // copies the block of 3 bytes into a single int
        int container = src[0];
        for (size_t i = 1; i < 3; i++)
            container = (container<<8) + src[i];
        // read the blocks of 6 bits and converts them to base64
        for (int i = 3; i >= 0; i--)
        {
            dst[i] = b64Table[container & 0x3f];
            container >>= 6;
        }
    }
    else if(length)
    {
        // concatenates the bytes into a signle int value
        int container = (length == 1) ?
            src[0] << 4 : ((src[0] << 8) + src[1]) << 2;
        // read the blocks of 6 bits and converts them to base64
        for (int i = 0; i < length+ 1; i++)
        {
            dst[i] = b64Table[NTH_BLOCK(container, length)];
            container <<= 6;
        }
        // adds final padding to the string
        char *padding = length == 1 ? "==" : "=";
        strcpy(dst + length+ 1, padding);
    }
}
// returns the base64 numerical value corresponding to c
int indexOf(const char c)
{
    int index=0;
    while(b64Table[index] != c && index < 64)
        index++;
    return index;
}
// reads a 4-character long base64 encoded string src, and writes the
// decoded bytes in dst
void decode(const char* src, char* dst)
{
    int container = 0;
    int l;
    // if there is no padding at the end of the string
    if(src[3] != '=')
    {
        // concatenates the 4 characters into container
        l = 3;
        for(int i=0; i<4; i++)
            container += indexOf(src[i]) << ((3-i) * 6);
    }
    // if there is a padding
    else
    {
        // counts the number of characters without the padding 
        l = 0;
        while(src[l] != '=') l++;
        // determines how many 0s have to be removed at the end
        // builds the container
        for(int i=0; i < l; i++)
            container += indexOf(src[i]) << (6 * (l-1-i));
        // removes the 0s at the end
        container >>= (l & 1)? 2 : 4;
        --l;
    }
    // reads the final bytes from container
    for (int i = 0; i < l; i++)
        dst[i] = container >> (8 * (l-1-i));
}