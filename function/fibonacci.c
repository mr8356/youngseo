#include <stdio.h>
#include <time.h>

#define MAX 100

int memo[MAX] = {0};

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fiboTopDown(int n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = fiboTopDown(n - 1) + fiboTopDown(n - 2);
    return memo[n];
}

int fiboBottomUp(int n) {
    if (n <= 1) return n;
    int dp[MAX] = {0};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    // Measure time for fibo
    start = clock();
    int fiboResult = fibonacci(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("(fibonacci): %d, Time: %f seconds\n", fiboResult, cpu_time_used);

    // Measure time for fiboTopDown
    start = clock();
    int topDownResult = fiboTopDown(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("(Top-down): %d, Time: %f seconds\n", topDownResult, cpu_time_used);

    // fiboBottomUp
    printf("(Bottom-up): %d\n", fiboBottomUp(n));

    return 0;
}
