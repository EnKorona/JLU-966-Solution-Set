/*
 * 1. 使用快慢指针，在快指针未走到链表末尾的前提下让快指针先走k步
 * 2. 如果还未走到k步，快指针所指节点已经为null，说明链表长度不超过k，返回0
 * 3. 如果走到k步，快指针所指节点不为null，则快慢指针同速前进，知道快指针所指节点为null，此时慢指针所指节点即为倒数第k个节点
 */

ListNode findKthFromEnd(ListNode list, int k) {
    ListNode fast = list->link, slow = list->link;
    while (fast != NULL && k > 0) {
        fast = fast->link;
        k--;
    }
    if (k != 0) return 0;    // 如果快指针已经到了链表尾，k未归零，则链表长度不足k，返回0
    while (fast != NULL) {
        fast = fast->link;
        slow = slow->link;
    }
    printf("倒数第k个节点的data域值为：%d", slow->data);
    return 1;
}

// 只对链表进行一次遍历，时间复杂度为O(n)