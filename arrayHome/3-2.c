#include <stdio.h>

int main() {
    int A[20];
    int F, R, M;

    // 배열 A에 1부터 20까지 저장
    for (int i = 0; i < 20; i++) {
        A[i] = i + 1;
    }

    // F, R, M 입력 받기
    printf("F, R, M을 입력하세요 (F < R < 20, M은 R-F+1보다 작음): ");
    scanf("%d %d %d", &F, &R, &M);

    // A[R]부터 A[R-M+1]까지의 정수를 오른쪽으로 이동
    int temp = A[R];
    for (int i = R; i > R - M + 1; i--) {
        A[i] = A[i - 1];
    }
    A[R - M + 1] = temp;

    // 배열 A 출력
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
