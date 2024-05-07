#include <stdio.h>

int main() {
    int N;
    
    // 정수 N 입력 받기
    scanf("%d", &N);
    
    // 각 자릿수의 곱 계산
    int M = 1;
    int temp = N;
    while (temp > 0) {
        M *= (temp % 10);
        temp /= 10;
    }
    temp = M;
    
    // M의 각 자릿수를 역순으로 바꾼 정수 출력
    int reversed_M = 0;
    while (M > 0) {
        reversed_M = reversed_M * 10 + (M % 10);
        M /= 10;
    }
    
    printf("%d %d\n", temp,reversed_M);

    return 0;
}
