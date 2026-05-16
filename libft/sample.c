#include <string.h>
#include <stdio.h>
#include "libft.h"

int main()
{
    printf("%d", memcmp(NULL, "abc", 0));
    printf("%d", memcmp(NULL, NULL, 0));
    // ft_memcmp(NULL, NULL, 0);
    return 0;
}