#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DATA 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序
void selectionSort(int arr[], int n, int *compareCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*compareCount)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n, int *compareCount) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*compareCount)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// 堆排序
void adjust(int arr[], int i, int n, int *compareCount) {
    int j, temp;
    temp = arr[i];
    j = 2 * i + 1;
    while (j < n) {
        (*compareCount)++;
        if (j < n - 1 && arr[j] < arr[j + 1]) {
            j++;
        }
        if (temp >= arr[j]) {
            break;
        }
        arr[(j - 1) / 2] = arr[j];
        j = 2 * j + 1;
    }
    arr[(j - 1) / 2] = temp;
}

void heapSort(int arr[], int n, int *compareCount) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjust(arr, i, n, compareCount);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        adjust(arr, 0, i, compareCount);
    }
}

// 二路归并排序
void merge(int arr[], int tmp[], int left, int leftend, int rightend, int *compareCount) {
    int i = left, j = leftend + 1, q = left;
    while (i <= leftend && j <= rightend) {
        (*compareCount)++;
        if (arr[i] <= arr[j]) {
            tmp[q++] = arr[i++];
        } else {
            tmp[q++] = arr[j++];
        }
    }
    while (i <= leftend) {
        tmp[q++] = arr[i++];
    }
    while (j <= rightend) {
        tmp[q++] = arr[j++];
    }
    for (i = left; i <= rightend; i++) {
        arr[i] = tmp[i];
    }
}

void mergeSort(int arr[], int tmp[], int left, int right, int *compareCount) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(arr, tmp, left, center, compareCount);
        mergeSort(arr, tmp, center + 1, right, compareCount);
        merge(arr, tmp, left, center, right, compareCount);
    }
}

// 快速排序
int partition(int arr[], int left, int right, int *compareCount) {
    int pivot = arr[left];
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        (*compareCount)++;
        if (arr[i] < pivot) {
            last++;
            swap(&arr[i], &arr[last]);
        }
    }
    swap(&arr[left], &arr[last]);
    return last;
}

void quickSort(int arr[], int left, int right, int *compareCount) {
    if (left < right) {
        int last = partition(arr, left, right, compareCount);
        quickSort(arr, left, last - 1, compareCount);
        quickSort(arr, last + 1, right, compareCount);
    }
}

int main() {
    int n, method;
    int arr[MAX_DATA];
    int tmp[MAX_DATA];
    int compareCount = 0;

    scanf("%d %d", &n, &method);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    switch (method) {
        case 1:
            selectionSort(arr, n, &compareCount);
            break;
        case 2:
            bubbleSort(arr, n, &compareCount);
            break;
        case 3:
            heapSort(arr, n, &compareCount);
            break;
        case 4:
            mergeSort(arr, tmp, 0, n - 1, &compareCount);
            break;
        case 5:
            quickSort(arr, 0, n - 1, &compareCount);
            break;
        default:
            return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n%d\n", compareCount);

    return 0;
}
