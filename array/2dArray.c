#include <stdio.h>

void printArr(int s[][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d][%d] = %d\n", i, j, *(*(s+i)+j));
        }
    }
}

int main()
{
    int s[][5] = {
        {0, 1, 2, 3, 4},      // 첫 번째 행의 원소들의 초기값
        {10, 11, 12, 13, 14}, // 두 번째 행의 원소들의 초기값
        {20, 21, 22, 23, 24}, // 세 번째 행의 원소들의 초기값
    };
    printArr(s);
    return 0;
}
