#include <stdio.h>
#define MAX_INPUT 30
int combination(int n, int r);
int factorial(int n);
int get_integer();
    int n;
    int a = get_integer();
    int b
    int i;
int main(void)
{
     = get_integer();
    printf("C(%d, %d) = %d \n", a, b, combination(a, b));
    return 0;
}

int combination(int n, int r)
{
    return (factorial(n) / (factorial(r) * factorial(n - r)));
}
int factorial(int n)
{
   
    long result = 1;
    for (i = 1; i <= n; i++)
        result *= i; // result = result * i
    return result;
}

int get_integer(void)
{

    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    return n;
}