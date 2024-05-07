#include <stdio.h>

int main() {
    char ch;
    int upper_cnt = 0, lower_cnt = 0, sum = 0, other_cnt = 0;
    while ((ch = getchar()) != '*') {
        if ((ch >= 'A' && ch <= 'Z')) {
            upper_cnt++;
        } else if ((ch >= 'a' && ch <= 'z')) {
            lower_cnt++;
        } else if ((ch >= '0' && ch <= '9')) {
            sum += (ch - '0');
        } else {
            other_cnt++;
        }
    }
    printf("%d %d %d %d", upper_cnt, lower_cnt, sum, other_cnt);
    return 0;
}
