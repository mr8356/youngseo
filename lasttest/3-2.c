#include <stdio.h>
// 사용자로부터 N과 M을 입력받습니다.
// N개의 정수를 배열에 입력받습니다.
// (1) M개씩 묶어서 평균값보다 크거나 같은 정수를 차례로 출력합니다.
// (2) M개씩 묶어서 가장 큰 수를 차례로 출력합니다.
// (3) M개씩 묶어서 가장 작은 수를 차례로 출력합니다.
int main() {
    int N, M;
    int arr[100];

    // N과 M 입력받기
    printf("N과 M을 입력하세요 (1 ≤ N ≤ 100, 1 ≤ M ≤ N): ");
    scanf("%d %d", &N, &M);

    // N개의 정수 입력받기
    printf("%d개의 양의 정수를 입력하세요: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // (1) M개 정수의 평균값보다 크거나 같은 정수를 차례로 출력
    printf("(1) ");
    for (int i = 0; i < N; i += M) {
        int sum = 0;
        int count = 0;
        for (int j = i; j < i + M && j < N; j++) {
            sum += arr[j];
            count++;
        }
        double avg = (double)sum / count;
        for (int j = i; j < i + M && j < N; j++) {
            if (arr[j] >= avg) {
                printf("%d ", arr[j]);
            }
        }
    }
    printf("\n");

    // (2) M개 정수 중 가장 큰 수를 차례로 출력
    printf("(2) ");
    for (int i = 0; i < N; i += M) {
        int max = arr[i];
        for (int j = i + 1; j < i + M && j < N; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
        }
        printf("%d ", max);
    }
    printf("\n");

    // (3) M개 정수 중 가장 작은 수를 차례로 출력
    printf("(3) ");
    for (int i = 0; i < N; i += M) {
        int min = arr[i];
        for (int j = i + 1; j < i + M && j < N; j++) {
            if (arr[j] < min) {
                min = arr[j];
            }
        }
        printf("%d ", min);
    }
    printf("\n");

    return 0;
}
