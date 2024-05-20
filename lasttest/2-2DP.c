#include <stdio.h>

int main() {
    int N;
    int arr[100];
    int dp[100];
    int start_indices[100];

    // N 입력 받기
    printf("양의 정수 N을 입력하세요 (N < 100): ");
    scanf("%d", &N);

    // N개의 정수 입력 받기
    printf("%d개의 정수를 입력하세요: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1; // 초기 부분 배열 길이는 1
        start_indices[i] = i; // 초기 시작 인덱스는 자기 자신
    }

    int max_length = 1;
    int max_index = 0;

    for (int i = 1; i < N; i++) {
        if ((arr[i] < 0 && arr[i - 1] > 0) || (arr[i] > 0 && arr[i - 1] < 0)) {
            dp[i] = dp[i - 1] + 1;
            start_indices[i] = start_indices[i - 1];
        }

        if (dp[i] > max_length) {
            max_length = dp[i];
            max_index = i;
        } else if (dp[i] == max_length) {
            max_index = i; // 같은 길이일 경우, 마지막 배열을 선택
        }
    }

    // 결과 출력
    printf("가장 긴 부분 배열의 크기: %d\n", max_length);
    printf("부분 배열: ");
    for (int i = start_indices[max_index]; i < start_indices[max_index] + max_length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
