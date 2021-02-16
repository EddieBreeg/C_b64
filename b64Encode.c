#include <stdio.h>
#include "src/b64.h"

int main(int argc, char const *argv[])
{
    FILE* f = fopen(argv[1], "rb");
    size_t offset = 0;
    if(argc > 2)
        offset = atoi(argv[2]);
    if(f) // the argument corresponds to an existing file:
    {
        fseek(f, offset, 0);
        char buffer[9] = {0};
        int n = fread(buffer, sizeof(char), 3, f);
        while(n)
        {
            encode(buffer, buffer+4, n);
            printf("%s", buffer+4);
            memset(buffer, 0, 9 * sizeof(char));
            n = fread(buffer, sizeof(char), 3, f);
        }
    }
    else // any other case:
    {
        const char* str = argv[1] + offset;
        char buffer[5] = {0};
        size_t l = strlen(str);
        for (size_t i = 0; i < l; i+=3)
        {
            encode(str + i, buffer, l - i);
            printf("%s", buffer);
            memset(buffer, 0, 4 * sizeof(char));
        }
        return 0;
    }
    printf("\n");
    return 0;
}
