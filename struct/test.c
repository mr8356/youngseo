#include <stdio.h>

void get(int max[], int min[], int a)
{
    int new_max[20], new_min[20]; // 복사본을 활용해야지 최대최소가 꼬이지 않고 구해짐
    for (int i = 0; i < a; i+=3)
    {
        new_max[i / 3] = max[i];
        new_min[i / 3] = min[i];
        for (int j = 0; j < 3 && i + j < a; j++)
        {
            if (new_max[i/3] < max[i + j])
            {
                new_max[i / 3] = max[i + j];
            }
            if (new_min[i/3] > min[i + j])
            {
                new_min[i / 3] = min[i + j];
            }
        }
    }
    if (a % 3 == 0)
    {
        a/=3;
    }
    else
    {
        a/=3;
        a++;
    }
    
    for (int i = 0; i < a; i++)
    {
        printf(" %d", new_max[i]);
    }
    printf("\n");
    for (int i = 0; i < a; i++)
    {
        printf(" %d", new_min[i]);
    }
    printf("\n");
    if (a>1)
    {
        get(new_max, new_min, a);
    }
    
}

int main()
{
    int n, x[20], max[20], min[20];
    int a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &x[i]);
    }
    a = n;
    get(x, x, a);
    return 0;
}