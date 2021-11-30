/*
 * 1. 设置4个指针，分别指向当前节点，当前节点的前一个节点，最小节点，最小节点的前一个节点
 * 2. 遍历链表的同时判断每个节点的data域与m最小节点data域的大小，如果小则更新最小节点即最小节点的前一个节点
 * 3. 遍历结束后将最小的节点移到表头
 */


ListNode *findMin(ListNode *list) {
    ListNode *pre = list, *p = list->next;
    ListNode *minPre = pre, *min = p;
    while (p != nullptr) {
        pre = p;
        p = p->next;
        if (p->data < min->data) {
            minPre = pre;
            min = p;
        }
    }
    if (minPre == list) return list;
    minPre->next = min->next;
    min->next = list;
    return min;
}