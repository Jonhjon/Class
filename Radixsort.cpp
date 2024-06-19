#include <stdio.h>
#include <stdlib.h>

// 获取数组中最大值的函数
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// 计数排序函数，用于基数排序
void countSort(int array[], int n, int exp) {
    int output[n]; // 输出数组
    int i, count[10] = {0};

    // 统计每个数字出现的次数
    for (i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;

    // 修改 count[i]，使其包含该数字的最终位置
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 构建输出数组
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // 将输出数组复制到原数组
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

// 基数排序函数
void radixSort(int array[], int n) {
    int m = getMax(array, n); // 获取数组中的最大值

    // 从个位数开始，对每一位进行计数排序
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, n, exp);
}

// 打印数组函数
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array:\n");
    printArray(data, n);

    radixSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);
    return 0;
}
