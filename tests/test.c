#include <stdio.h>
#include "../src/b64.h"

int main(int argc, char const *argv[])
{
    FILE* in = fopen("data", "rb");
    FILE* out = fopen("enc", "wb");
    byte input[3], enc[4];

    size_t n = fread(input, 1, 3, in);
    while(n)
    {
        encode(input, enc, n);
        fwrite(enc, 1, 4, out);
        n = fread(input, 1, 3, in);
    }

    fclose(in); fclose(out);
    
    return 0;
}
