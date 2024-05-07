#include <stdio.h>

int main() {
    char ch, last_lower = 'a', first_upper = 'Z';
    while ((ch = getchar()) != '0') {
        if (ch >= 'a' && ch <= 'z') {
            // 소문자만 입력된 경우
            if (ch > last_lower) {
                last_lower = ch;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            // 대문자만 입력된 경우
            if (ch < first_upper) {
                first_upper = ch;
            }
        }
    }
    
    if (last_lower != 'a') {
        printf("%c", last_lower);
    } else if (first_upper != 'Z') {
        printf("%c", first_upper);
    }

    return 0;
}
