#include <stdio.h>
// 함수 중간에 재귀 호출이 발생하면?
void up_and_down(int n);
int main(void)
{
    up_and_down(1);
    return 0;
}
void up_and_down(int n)
{
    printf("Level %d before a recursion\n", n);
    if (n < 4)
        up_and_down(n + 1);
    printf("Level %d after a recursion\n", n);
}