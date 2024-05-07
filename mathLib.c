#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
double a = 2;
double b = 16;
int c = -3;
printf("square root of a is %.2lf.\n",sqrt(a));
printf("b^a is %.0lf.\n",pow(b,a));
printf("absolute value of c is %d.\n",abs(c));
printf("log(b) is %.2lf.\n",log(b)); // 자연 로그 logeb, log10(param): base 10
return 0;
}