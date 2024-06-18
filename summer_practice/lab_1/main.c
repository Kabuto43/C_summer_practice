#include <stdio.h>
#include <stdlib.h>
#include "library.h"

void two_numbers() {
    int a, b;
    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);
    printf("Maximum by value: %d\n", maxOfTwo(a, b));
    printf("Minimum by value: %d\n", minOfTwo(a, b));
    printf("Maximum by absolute value: %d\n", absMaxOfTwo(a, b));
    printf("Minimum by absolute value: %d\n", absMinOfTwo(a, b));
}

void three_numbers() {
    int a, b, c;
    printf("Enter three numbers:\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Maximum by value: %d\n", maxOfThree(a, b, c));
    printf("Minimum by value: %d\n", minOfThree(a, b, c));
    printf("Maximum by absolute value: %d\n", absMaxOfThree(a, b, c));
    printf("Minimum by absolute value: %d\n", absMinOfThree(a, b, c));
}

void n_numbers() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int* numbers = (int*)malloc(n * sizeof(int));
    if (!numbers) {
        printf("Memory allocation error.\n");
        return;
    }
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }
    printf("Maximum by value: %d\n", maxOf(numbers, n));
    printf("Minimum by value: %d\n", minOf(numbers, n));
    printf("Maximum by absolute value: %d\n", absMaxOf(numbers, n));
    printf("Minimum by absolute value: %d\n", absMinOf(numbers, n));
    free(numbers);
}

void table_nm() {
    int n, m;
    printf("Enter the dimensions of the table (n m):\n");
    scanf("%d %d", &n, &m);
    int* table = (int*)malloc(n * m * sizeof(int));
    if (!table) {
        printf("Memory allocation error.\n");
        return;
    }
    printf("Enter the table elements:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &table[i * m + j]);
        }
    }
    printf("Maximum by value: %d\n", maxInMatrix(n, m, table));
    printf("Minimum by value: %d\n", minInMatrix(n, m, table));
    printf("Maximum by absolute value: %d\n", absMaxInMatrix(n, m, table));
    printf("Minimum by absolute value: %d\n", absMinInMatrix(n, m, table));
    free(table);
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose data type:\n");
        printf("1. Two numbers\n");
        printf("2. Three numbers\n");
        printf("3. N numbers\n");
        printf("4. Table N*M\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                two_numbers();
                break;
            case 2:
                three_numbers();
                break;
            case 3:
                n_numbers();
                break;
            case 4:
                table_nm();
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}