#include <stdio.h>
#define SIZE 5
int main(void)
{
    // int array[5] = {1, 2, 3, 4, 5};
    // // char str[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    // // char str[6] = "Hello";
    // // char str[] = "C Bible";
    // int i;
    // for (i = 0; i < sizeof(array) / sizeof(array[0])+10; i++)
    //     printf("array[%d] %d\n", i, array[i]);

    char str[100];
    scanf("%s", str);
    printf("%c", str[0]);
    return 0;
}