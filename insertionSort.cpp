#include <stdio.h>

// 打印数组函数
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 插入排序函数
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        printf("Round %d: \n", i);
        printf("Current key: %d\n", key);

        // 将大于key的元素向后移动
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            printArray(array, n);
        }
        array[j + 1] = key;

        printf("After inserting key: \n");
        printArray(array, n);
        printf("\n");
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array:\n");
    printArray(data, n);

    insertionSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);
    return 0;
}
