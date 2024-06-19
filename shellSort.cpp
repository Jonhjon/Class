#include <stdio.h>

// 打印数组函数
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 谢尔排序函数
void shellSort(int array[], int n) {
    // 初始间隔值
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从间隔值开始进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    int data[] = {12, 34, 54, 2, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array:\n");
    printArray(data, n);

    shellSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);
    return 0;
}
