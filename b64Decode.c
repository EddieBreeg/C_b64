#include "src/b64.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* f = fopen(argv[1], "r");
    size_t offset = 0;
    if(argc > 2)
        offset = atoi(argv[2]);
        
    if(f) // the argument corresponds to an existing file:
    {
        fseek(f, offset, 0);
        char buffer[9] = {0};
        int n = fread(buffer, sizeof(char), 4, f);
        while(n == 4)
        {
            decode(buffer, buffer+5);
            printf("%s", buffer+5);
            memset(buffer, 0, 9 * sizeof(char));
            n = fread(buffer, sizeof(char), 4, f);
        }
    }
    else // any other case:
    {
        const char* str = argv[1] + offset;
        char buffer[4] = {0};
        size_t l = strlen(str);
        if(l % 4)
        {
            printf("Invalid string length: %d. Decoding failed.\n", l);
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < l; i+=4)
        {
            decode(str + i, buffer);
            printf("%s", buffer);
            memset(buffer, 0, 4 * sizeof(char));
        }
    }
    printf("\n");
    return 0;
}
