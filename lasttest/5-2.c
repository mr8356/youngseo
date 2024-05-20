#include <stdio.h>
#include <stdbool.h>
// 사용자로부터 문자열을 입력받습니다. 이 때, '!' 문자가 입력되면 입력을 종료합니다.
// 정수 M을 입력받습니다.
// 중복된 문자를 제거하여 Y 배열에 저장합니다.
// Y 배열의 각 문자에 대해 M 만큼 증가시킵니다.
// Y 배열에서 교대로 나오는 가장 긴 부분 배열을 찾아 출력합니다. 만약 조건을 만족하는 부분 배열이 없으면 "none"을 출력합니다.
void remove_duplicates(char X[], char Y[], int *size_X, int *size_Y) {
    bool found[26] = {false}; // 알파벳 출현 여부를 저장하는 배열
    *size_Y = 0;

    for (int i = 0; i < *size_X; i++) {
        if (!found[X[i] - 'a'] && !found[X[i] - 'A']) {
            Y[*size_Y] = X[i];
            (*size_Y)++;
            found[X[i] - 'a'] = true;
            found[X[i] - 'A'] = true;
        }
    }
}

void shift_characters(char Y[], int size_Y, int M) {
    for (int i = 0; i < size_Y; i++) {
        if (Y[i] >= 'a' && Y[i] <= 'z') {
            Y[i] = 'a' + (Y[i] - 'a' + M) % 26;
        } else {
            Y[i] = 'A' + (Y[i] - 'A' + M) % 26;
        }
    }
}

void find_alternating_subarray(char Y[], int size_Y) {
    int max_length = 0;
    int start_index = -1;
    int current_length = 0;

    for (int i = 0; i < size_Y - 1; i++) {
        if ((Y[i] >= 'a' && Y[i + 1] >= 'A') || (Y[i] >= 'A' && Y[i + 1] >= 'a')) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                start_index = i - current_length + 1;
            }
            current_length = 0;
        }
    }

    if (current_length > max_length) {
        max_length = current_length;
        start_index = size_Y - current_length;
    }

    if (max_length > 0) {
        printf("%d\n", max_length + 1);
        for (int i = start_index; i <= start_index + max_length; i++) {
            printf("%c", Y[i]);
        }
        printf("\n");
    } else {
        printf("none\n");
    }
}

int main() {
    char X[100], Y[26];
    int size_X = 0, size_Y = 0;
    int M;

    // X 배열 입력 받기
    char c;
    while ((c = getchar()) != '!') {
        X[size_X++] = c;
    }

    // M 입력 받기
    scanf("%d", &M);

    // (1) 중복 문자 제거하여 Y 배열에 저장하기
    remove_duplicates(X, Y, &size_X, &size_Y);

    // (2) Y 배열의 각 문자를 시프트하여 저장하기
    shift_characters(Y, size_Y, M);

    // (3) 교대로 나오는 부분 배열 찾기
    find_alternating_subarray(Y, size_Y);

    return 0;
}
