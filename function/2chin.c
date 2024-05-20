#include <stdio.h>
int memo[100] = {0};

int solve(int n){
    if (n <= 2){
        return 1;
    }
    else if (memo[n]!=0)
    {
        return memo[n];
    }
    else
    {
        memo[n] = solve(n-1) + solve(n-2);
        return memo[n];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d",solve(n));
}