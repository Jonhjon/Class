#include <stdio.h>

// 打印数组函数
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 合并函数，将两个子数组合并为一个有序数组
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1; // 左子数组的长度
    int n2 = right - mid; // 右子数组的长度

    // 创建临时数组存放子数组
    int leftArray[n1], rightArray[n2];

    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = array[mid + 1 + i];

    // 合并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // 复制剩余的元素（如果有的话）
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// 合并排序函数
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 递归地对左右子数组进行排序
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // 合并排序后的子数组
        merge(array, left, mid, right);
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array:\n");
    printArray(data, n);

    mergeSort(data, 0, n - 1);

    printf("Sorted array:\n");
    printArray(data, n);
    return 0;
}
