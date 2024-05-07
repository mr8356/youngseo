#include <stdio.h>
#define NUM 5
int main(){
    int score[NUM];
    float avg = 0;
    int cnt_under_40 = 0;
    int min = 100;
    for (int i = 0; i < NUM; i++)
    {
        scanf("%d", &score[i]);
        if (score[i] < 0 || score[i]>100)
        {
            printf("Invalid");
            return 0;
        }
        if (score[i] <= 40)
        {
            cnt_under_40 += 1;
        }
        if (score[i] <= min)
        {
            min = score[i];
        }
        avg += score[i];
    }
    avg = (float)avg /  NUM;
    if (cnt_under_40 >= 3)
    {
        printf("F\n");
    }
    else if (avg>=90)
    {
        printf("A+\n");
    }
    else if (avg>=75)
    {
       printf("A\n");
    }
    else if (avg>=65)
    {
       printf("B+\n");
    }
    else if (avg>=50)
    {
       printf("B\n");
    }
    else
    {
        printf("F\n");
    }
    printf("avg=%.2f min=%d", avg, min);
}