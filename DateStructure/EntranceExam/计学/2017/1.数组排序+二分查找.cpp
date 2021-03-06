/*
 * 1. 通过堆排序算法，将A数组调整有序
 * 2. 通过二分查找算法循环查找A中有多少个值小于等于B[i]
 * 3. 将该值赋值给数组C[i]
 */

void heapSort(int arr[], int len) {
    // 构建大顶堆
    for (int i = len / 2 - 1; i >= 0; i--) { // 从第一个非叶节点开始，从下至上，从右至左调整结构
        adjustDown(arr, i, len);
    }
    // 交换堆顶元素与末尾元素，调整堆结构
    for (int j = len - 1; j > 0; j--) {
        swap(arr, 0, j); // 将堆顶元素与末尾元素进行交换
        adjustDown(arr, 0, j); // 重新对堆进行调整
    }
}

void adjustDown(int arr[], int i, int len) {
    int temp = arr[i];
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
        if (k + 1 < len && arr[k] < arr[k + 1]) k++ //如果左子节点小于右子节点，k指向右子节点
        if (arr[k] > temp) {
            arr[i] = arr[k];
            i = k;
        }
    }
    arr[i] = temp;
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int binarySearch(int arr[], int len, int key) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return high;
}

void getArrayC(int A[], int B[], int C[], int len) {
    heapSort(A, len);
    for (int i = 0; i < len; i++) {
        C[i] = binarySearch(A, n, B[i]);
    }
}