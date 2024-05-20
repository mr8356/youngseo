#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int A[MAX_SIZE] = {0}; // 집합 A를 나타내는 배열 초기화
    int B[MAX_SIZE] = {0}; // 집합 B를 나타내는 배열 초기화
    int num;

    // 집합 A 입력
    while (1) {
        scanf("%d", &num);
        if (num < 0) break; // 음수 입력 시 종료
        A[num] = 1; // 집합 A에 해당 인덱스를 1로 설정
    }

    // 집합 B 입력
    while (1) {
        scanf("%d", &num);
        if (num < 0) break; // 음수 입력 시 종료
        B[num] = 1; // 집합 B에 해당 인덱스를 1로 설정
    }

    // 합집합 출력
    for (int i = 0; i < MAX_SIZE; i++) {
        if (A[i] || B[i]) { // A나 B 중에 해당 인덱스가 있는 경우 출력
            printf("%d ", i);
        }
    }

    return 0;
}
