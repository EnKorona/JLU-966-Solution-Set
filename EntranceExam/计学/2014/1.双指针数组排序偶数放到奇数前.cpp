/*
 * 1. 使用双指针，指针i、j分别指向数组第一个值和最后一个值，向中间移动
 * 2. 当i和j未相遇时，i查找相遇点左侧的奇数，j查找相遇点右侧的偶数，交换i和j所指的函数值
 * 3. 重复步骤2，直至i和j相遇，则相遇点左侧全部为偶数，右侧全部为奇数
 * 【leetcode】0905
 */


void sortArrayByParity(int S[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && S[i] % 2 == 0) i++;
        while (i < j && S[j] % 2 != 0) j--;
        if (i < j) {
            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;
        }
    }
}