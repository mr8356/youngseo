#include <stdio.h>

int main() {
    int N, M = 0, reversed_M = 0;
    int cnt_multiple_2 = 0, cnt_multiple_3 = 0;

    scanf("%d", &N);

    while (N > 0) {
        M = M * 10 + (N % 10);
        reversed_M = reversed_M * 10 + (N % 10);
        N /= 10;
    }

    for (int i = 1; i <= M; i++) {
        if (i % 2 == 0) {
            cnt_multiple_2++;
        }
        if (i % 3 == 0) {
            cnt_multiple_3++;
        }
    }

    printf("%d\n", reversed_M);
    printf("%d %d", cnt_multiple_2, cnt_multiple_3);
    return 0;
}
