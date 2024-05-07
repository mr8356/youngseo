#include <stdio.h>
int main(void)
{
    // int i = 3000;
    // int *p = &i;             // 변수와 포인터 연결
    // printf("&i = %u\n", &i); // 변수의 주소 출력
    // printf("p = %u\n", p);   // 포인터의 값 출력
    // printf("i = %d\n", i);   // 변수의 값 출력
    // printf("*p = %d\n\n\n", *p); // 포인터를 통한 간접 참조 값 출력

    int arr[5] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}