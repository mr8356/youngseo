#include <stdio.h>

int main() {
    int N;
    int arr[100];
    int longest_start = 0, longest_length = 1;
    int current_start = 0, current_length = 1;

    // N 입력 받기
    printf("양의 정수 N을 입력하세요 (N < 100): ");
    scanf("%d", &N);

    // N개의 정수 입력 받기
    printf("%d개의 정수를 입력하세요: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 가장 긴 부호가 교대로 나오는 부분 배열 찾기
    for (int i = 1; i < N; i++) {
        if ((arr[i] < 0 && arr[i-1] > 0) || (arr[i] > 0 && arr[i-1] < 0)) {
            current_length++;
            if (current_length >= longest_length) {
                longest_length = current_length;
                longest_start = i - current_length + 1;
            }
        } else {
            current_start = i;
            current_length = 1;
        }
    }

    // 결과 출력
    printf("가장 긴 부분 배열의 크기: %d\n", longest_length);
    printf("부분 배열: ");
    for (int i = longest_start; i < longest_start + longest_length; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
