#include <stdio.h>
#define NUM_CLASSMATE 5
int main(){
    int score[NUM_CLASSMATE];
    float avg = 0;
    for (int i = 0; i < NUM_CLASSMATE; i++)
    {
        scanf("%d", &score[i]);
        avg += score[i];
    }
    avg /= NUM_CLASSMATE;
    if (avg>=90)
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
    printf("%.2f", avg);
    
}


// #include <stdio.h>
// int main(){
//     int a,b,c,d,e;
//     scanf("%d %d %d %d %d",&a, &b, &c, &d, &e);
//     float avg = (a+b+c+d+e)/5;
//     if (avg>=90)
//     {
//         printf("A+\n");
//     }
//     else if (avg>=75)
//     {
//        printf("A\n");
//     }
//     else if (avg>=65)
//     {
//        printf("B+\n");
//     }
//     else if (avg>=50)
//     {
//        printf("B\n");
//     }
//     else
//     {
//         printf("F\n");
//     }
//     printf("%.2f", avg);
    
// }