#include <stdio.h>

int main() {
    char ch, last_lower = 'a', first_upper = 'Z';
    int has_lower = 0, has_upper = 0;
    char first_ch = getchar();
    if (first_ch >= 'a' && first_ch <= 'z') {
            has_lower = 1;
            if (first_ch > last_lower) {
                last_lower = first_ch;
            }
        }
        if (first_ch >= 'A' && first_ch <= 'Z') {
            has_upper = 1;
            if (first_ch < first_upper) {
                first_upper = first_ch;
            }
        }
    while ((ch = getchar()) != '0') {
        if (ch >= 'a' && ch <= 'z') {
            has_lower = 1;
            if (ch > last_lower) {
                last_lower = ch;
            }
        }
        if (ch >= 'A' && ch <= 'Z') {
            has_upper = 1;
            if (ch < first_upper) {
                first_upper = ch;
            }
        }
    }
    
    // 첫문자가 소문자 / 소문자'대문자' 혼합
    if (first_ch >= 'a' && first_ch <= 'z') {
        if (has_upper) {
            printf("%c%c\n",last_lower, first_upper);
        }
        else
        {
           printf("%c\n", last_lower);
        }
        
    }
    // 첫문자가 대문자 / 대문자'소문자' 혼합
    else
    {
        if (has_lower) {
            printf("%c%c\n", first_upper, last_lower);
        }
        else {
            printf("%c\n", first_upper);
        }
    }
    return 0;
}
