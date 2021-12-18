
ListNode *insertionSort(ListNode *head) {
    if (head == nullptr) return head;
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;     //创建哑节点
    ListNode *lastSorted = head;    //有序部分的最后一个节点
    ListNode *cur = head->next;
    while (cur != nullptr) {
        if (lastSorted->val <= cur->val) { //如果当前节点大于等于有序部分的最后一个节点，则直接将其加入有序部分
            lastSorted = lastSorted->next;
        } else {    //否则从头节点开始向后遍历，直至找到插入位置
            ListNode *pre = dummyHead;
            while (pre->next->val <= cur->val) {
                pre = pre->next;
            }
            lastSorted->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        cur = lastSorted->next;
    }
    return dummyHead->next;
}