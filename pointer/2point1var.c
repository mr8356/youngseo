#include <stdio.h>
int main(void)
{
    int i = 10000; // 정수 변수 정의
    int *p, *q;    // 정수형 포인터 정의
    p = &i;        // 포인터 p와 변수 i를 연결
    q = &i;        // 포인터 q와 변수 i를 연결
    *p = *p + 1;   // 포인터 p를 통하여 1 증가
    *q = *q + 1;   // 포인터 q를 통하여 1 증가
    printf("i = %d\n", i);
    return 0;
}