#include <stdio.h>

int main() {
    char ch, min1 = 'z', min2 = 'z';
    while ((ch = getchar()) >= 'a' && ch <= 'z') {
        if (ch < min1) {
            min2 = min1;
            min1 = ch;
        } else if (ch < min2 && ch != min1) {
            min2 = ch;
        }
    }
    printf("%c%c\n", min1, min2);
    return 0;
}
