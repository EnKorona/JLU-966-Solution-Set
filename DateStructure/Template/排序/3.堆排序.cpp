
void heapSort(int arr[]) {
    // 构建大顶堆
    int len = sizeof(arr);
    for (int i = len / 2 - 1; i >= 0; i--) {
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