#include <stdio.h>
// addElement 함수를 사용하여 새로운 원소를 집합에 추가합니다. 중복된 원소는 추가되지 않습니다.
// unionSets 함수를 사용하여 두 집합의 합집합을 구합니다.
// 구한 합집합을 오름차순으로 정렬합니다.
// 정렬된 합집합을 출력합니다.
#define MAX_SIZE 100

// 집합에 새로운 원소 추가
void addElement(int set[], int *setSize, int element) {
    for (int i = 0; i < *setSize; i++) {
        if (set[i] == element) {
            return; // 이미 존재하는 원소이므로 추가하지 않음
        }
    }
    set[*setSize] = element;
    (*setSize)++;
}

// 두 집합의 합집합 구하기
void unionSets(int setA[], int sizeA, int setB[], int sizeB, int resultSet[], int *resultSize) {
    for (int i = 0; i < sizeA; i++) {
        addElement(resultSet, resultSize, setA[i]);
    }
    for (int i = 0; i < sizeB; i++) {
        addElement(resultSet, resultSize, setB[i]);
    }
}

// 오름차순으로 정렬
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int setA[MAX_SIZE], setB[MAX_SIZE], resultSet[MAX_SIZE];
    int sizeA = 0, sizeB = 0, resultSize = 0;
    int num;

    // 집합 A 입력 받기
    printf("집합 A 입력 (-1 입력 시 종료): ");
    while (scanf("%d", &num) && num != -1) {
        addElement(setA, &sizeA, num);
    }

    // 집합 B 입력 받기
    printf("집합 B 입력 (-1 입력 시 종료): ");
    while (scanf("%d", &num) && num != -1) {
        addElement(setB, &sizeB, num);
    }

    // 합집합 구하기
    unionSets(setA, sizeA, setB, sizeB, resultSet, &resultSize);

    // 합집합 정렬
    sort(resultSet, resultSize);

    // 정렬된 합집합 출력
    printf("합집합: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");

    return 0;
}
