#include <stdio.h>
#include <stdlib.h>
// 학생 수 입력: N과 각 학생의 1차 및 2차 인증점수를 입력받습니다.
// 평균 점수 계산: 각 학생의 평균 점수를 1차 점수의 40%와 2차 점수의 60%를 합산하여 계산합니다.
// 평균 점수 기준으로 정렬: qsort를 사용하여 평균 점수를 기준으로 학생들을 내림차순으로 정렬합니다.
// 등수 계산: 평균 점수를 기준으로 등수를 계산합니다. 동점일 경우 동일한 등수를 부여합니다.
// 학점 부여: 상위 30%에게 A, 상위 70%에게 B, 나머지에게 F를 부여합니다. 2차 인증점수가 60점 이상인 경우 F를 B로 변경합니다.
// 결과 출력: 학생의 1차 점수, 2차 점수, 평균 점수, 등수 및 학점을 출력합니다.

typedef struct {
    int id;
    int first_score;
    int second_score;
    double average;
    int rank;
    char grade;
} Student;

int compare(const void* a, const void* b) {
    double diff = ((Student*)b)->average - ((Student*)a)->average;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int main() {
    int N;
    Student students[20];

    // (1) 학생 수 입력받기
    printf("학생 수를 입력하세요 (N ≤ 20): ");
    scanf("%d", &N);

    // 1차 인증 점수 입력받기
    printf("1차 인증 점수를 입력하세요: ");
    for (int i = 0; i < N; i++) {
        students[i].id = i;
        scanf("%d", &students[i].first_score);
    }

    // 2차 인증 점수 입력받기
    printf("2차 인증 점수를 입력하세요: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].second_score);
    }

    // (2) 평균 점수 계산하기
    for (int i = 0; i < N; i++) {
        students[i].average = students[i].first_score * 0.4 + students[i].second_score * 0.6;
    }

    // (3) 평균 점수 기준으로 내림차순 정렬하기
    qsort(students, N, sizeof(Student), compare);

    // (4) 등수 계산하기
    for (int i = 0; i < N; i++) {
        if (i > 0 && students[i].average == students[i - 1].average) {
            students[i].rank = students[i - 1].rank;
        } else {
            students[i].rank = i + 1;
        }
    }

    // (5) 학점 부여하기
    int a_count = 0, b_count = 0;
    int a_limit = (int)(N * 0.3 + 0.5);
    int b_limit = (int)(N * 0.7 + 0.5);

    for (int i = 0; i < N; i++) {
        if (a_count < a_limit) {
            students[i].grade = 'A';
            a_count++;
        } else if (b_count < b_limit - a_count) {
            students[i].grade = 'B';
            b_count++;
        } else {
            students[i].grade = 'F';
        }
    }

    for (int i = 0; i < N; i++) {
        if (students[i].grade == 'F' && students[i].second_score >= 60) {
            students[i].grade = 'B';
        }
    }

    // (6) 결과 출력하기
    printf("1차 인증점수 2차 인증점수 평균점수 등수 학점\n");
    for (int i = 0; i < N; i++) {
        printf("%d %d %.1f %d %c\n",
               students[i].first_score,
               students[i].second_score,
               students[i].average,
               students[i].rank,
               students[i].grade);
    }

    return 0;
}
