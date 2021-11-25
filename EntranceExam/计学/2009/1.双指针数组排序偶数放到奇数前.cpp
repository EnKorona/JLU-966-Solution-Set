/*
 * 1. 首先设置最小值的初值为头节点的val值，遍历链表的同时比较当前节点的值与最小节点的值，如果比min小则更新min值，最后返回min值
 */

int findMin(ListNode *head) {
    int min = head->val;
    while (head != nullptr) {
        if (head->val < min) min = head->val;
        head = head->next;
    }
    return min;
}