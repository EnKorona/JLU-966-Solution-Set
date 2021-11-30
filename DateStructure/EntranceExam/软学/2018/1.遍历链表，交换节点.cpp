/*
 * 1. 定义两个指针，p指向当前节点，pre指向前驱节点
 * 2. 当p -> data == k的时候，交换p -> data和pre -> data
 */

ListNode exchange(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *pre = head, p = head->next;
    while (p) {
        if (p->data == k) {
            int temp = p->data;
            p->data = pre->data;
            pre->data = temp;
        }
        pre = p;
        p = p->next;
    }
}
