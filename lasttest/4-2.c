#include <stdio.h>
// 사용자로부터 학생 수 N과 각 학생의 1차 및 2차 인증점수를 입력받습니다.
// 각 학생의 평균 점수를 1차 점수의 40%와 2차 점수의 60%를 합산하여 계산합니다.
// 버블 정렬 알고리즘을 사용하여 평균 점수를 기준으로 학생들을 내림차순으로 정렬합니다.
// 정렬된 학생들의 평균 점수를 기준으로 등수를 계산합니다. 동점인 경우 같은 등수를 부여합니다.
// 상위 30%에게 A, 상위 70%에게 B, 나머지에게 F를 부여합니다. 2차 인증점수가 60점 이상인 경우 F를 B로 변경합니다.
// 각 학생의 1차 점수, 2차 점수, 평균 점수, 등수 및 학점을 출력합니다.
void swap(double *xp, double *yp) {
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapInt(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char *xp, char *yp) {
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(double averages[], int first_scores[], int second_scores[], int ranks[], char grades[], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (averages[j] < averages[j+1]) {
                swap(&averages[j], &averages[j+1]);
                swapInt(&first_scores[j], &first_scores[j+1]);
                swapInt(&second_scores[j], &second_scores[j+1]);
                swapInt(&ranks[j], &ranks[j+1]);
                swapChar(&grades[j], &grades[j+1]);
            }
        }
    }
}

int main() {
    int N;
    int first_scores[20], second_scores[20];
    double averages[20];
    int ranks[20];
    char grades[20];

    // (1) 학생 수 입력받기
    printf("학생 수를 입력하세요 (N ≤ 20): ");
    scanf("%d", &N);

    // 1차 인증 점수 입력받기
    printf("1차 인증 점수를 입력하세요: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &first_scores[i]);
    }

    // 2차 인증 점수 입력받기
    printf("2차 인증 점수를 입력하세요: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &second_scores[i]);
    }

    // (2) 평균 점수 계산하기
    for (int i = 0; i < N; i++) {
        averages[i] = first_scores[i] * 0.4 + second_scores[i] * 0.6;
    }

    // (3) 평균 점수 기준으로 내림차순 정렬하기
    for (int i = 0; i < N; i++) {
        ranks[i] = i + 1; // 초기 등수는 인덱스 + 1
    }
    sort(averages, first_scores, second_scores, ranks, grades, N);

    // (4) 등수 계산하기
    for (int i = 0; i < N; i++) {
        if (i > 0 && averages[i] == averages[i - 1]) {
            ranks[i] = ranks[i - 1];
        } else {
            ranks[i] = i + 1;
        }
    }

    // (5) 학점 부여하기
    int a_count = 0, b_count = 0;
    int a_limit = (int)(N * 0.3 + 0.5);
    int b_limit = (int)(N * 0.7 + 0.5);

    for (int i = 0; i < N; i++) {
        if (a_count < a_limit) {
            grades[i] = 'A';
            a_count++;
        } else if (b_count < b_limit - a_count) {
            grades[i] = 'B';
            b_count++;
        } else {
            grades[i] = 'F';
        }
    }

    for (int i = 0; i < N; i++) {
        if (grades[i] == 'F' && second_scores[i] >= 60) {
            grades[i] = 'B';
        }
    }

    // (6) 결과 출력하기
    printf("1차 인증점수 2차 인증점수 평균점수 등수 학점\n");
    for (int i = 0; i < N; i++) {
        printf("%d %d %.1f %d %c\n",
               first_scores[i],
               second_scores[i],
               averages[i],
               ranks[i],
               grades[i]);
    }

    return 0;
}
