#include <stdio.h>

void swap(int* pa, int* pb){
    int temp = *pb;
    *pb = *pa;
    *pa = temp;
}

int main(void) {
    int a = 6;
    int b = 8;
    swap(&a, &b);
    printf("%d %d", a, b);
}
