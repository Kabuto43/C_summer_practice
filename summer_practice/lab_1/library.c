#include "library.h"
#include <stdlib.h>

int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

int maxOfThree(int a, int b, int c) {
    return maxOfTwo(maxOfTwo(a, b), c);
}

int maxOf(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int maxInMatrix(int rows, int cols, int *matrix) {
    int max = matrix[0];
    for (int i = 0; i < rows * cols; ++i) {
        if (matrix[i] > max) {
            max = matrix[i];
        }
    }
    return max;
}

int absMaxOfTwo(int a, int b) {
    return maxOfTwo(abs(a), abs(b));
}

int absMaxOfThree(int a, int b, int c) {
    return maxOfThree(abs(a), abs(b), abs(c));
}

int absMaxOf(int arr[], int n) {
    int max = abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
        }
    }
    return max;
}

int absMaxInMatrix(int rows, int cols, int *matrix) {
    int max = abs(matrix[0]);
    for (int i = 0; i < rows * cols; ++i) {
        if (abs(matrix[i]) > max) {
            max = abs(matrix[i]);
        }
    }
    return max;
}

int minOfTwo(int a, int b) {
    return (a < b) ? a : b;
}

int minOfThree(int a, int b, int c) {
    return minOfTwo(minOfTwo(a, b), c);
}

int minOf(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int minInMatrix(int rows, int cols, int *matrix) {
    int min = matrix[0];
    for (int i = 0; i < rows * cols; ++i) {
        if (matrix[i] < min) {
            min = matrix[i];
        }
    }
    return min;
}

int absMinOfTwo(int a, int b) {
    return minOfTwo(abs(a), abs(b));
}

int absMinOfThree(int a, int b, int c) {
    return minOfThree(abs(a), abs(b), abs(c));
}

int absMinOf(int arr[], int n) {
    int min = abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) < min) {
            min = abs(arr[i]);
        }
    }
    return min;
}

int absMinInMatrix(int rows, int cols, int *matrix) {
    int min = abs(matrix[0]);
    for (int i = 0; i < rows * cols; ++i) {
        if (abs(matrix[i]) < min) {
            min = abs(matrix[i]);
        }
    }
    return min;
}