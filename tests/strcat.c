#include <stdio.h>
#include <stdlib.h>
char *_strcat(char *dest, const char *src)
{
        int dest_len = 0, i = 0, TOTAL_LEN = 64;

        while (dest[dest_len] != '\0')
        {
                dest_len++;
        }

        while (src[i] != '\0' && i < TOTAL_LEN - dest_len)
        {
                dest[dest_len + i] = src[i];
                i++;
        }
        dest[dest_len + i] = '\0';

        return (dest);
}
int main() {
    char dest[64] = "Hello, ";
    const char *src = "World!";

    _strcat(dest, src);

    printf("Concatenated string: %s\n", dest);

    return 0;
}
