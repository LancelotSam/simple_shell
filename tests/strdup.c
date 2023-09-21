#include <stdio.h>
#include <stdlib.h>
char *_strdup(const char *src)
{
        int len = 0;
        char *str;
        char *p;

        if (src == NULL)
                return (NULL);
        while (src[len])
        {
                len++;
        }
        /*allocate memory to store duplice*/
        str = malloc(len + 1);

        if (str == NULL)
        {
                perror("mem allocation failed");
                return (NULL);
        }
        /*since you cannot manipulate str, assign it to a pointer*/
        p = str;
        /*copy src to str*/
        while (*src)
        {
                *p++ = *src++;
        }
        *p = '\0';

        return (str);
}
int main() {
    const char *original = "Hello, World!";
    char *duplicate = _strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } else {
        printf("Failed to duplicate the string.\n");
    }

    return 0;
}
