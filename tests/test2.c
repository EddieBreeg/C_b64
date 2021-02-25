#include <stdio.h>
#include "../src/b64.h"

int main(int argc, char const *argv[])
{
    FILE* in = fopen("enc", "rb");
    FILE* out = fopen("dec", "wb");
    byte input[4], dec[3];

    size_t n = fread(input, 1, 4, in);
    while(n)
    {
        memset(dec, 0, 3);
        int l = decode(input, dec);
        fwrite(dec, 1, l, out);
        n = fread(input, 1, 4, in);
    }

    fclose(in); fclose(out);
    
    return 0;
}