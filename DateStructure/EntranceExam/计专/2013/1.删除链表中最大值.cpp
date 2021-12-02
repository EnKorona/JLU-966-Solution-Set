ListNode *deleteMax(ListNode *head) {
    ListNode *pre = head, *p = head->next;
    ListNode *maxPre = pre, *max = p;
    while (p != nullptr) {
        pre = p;
        p = p->next;
        if (p->data > max->data) {
            maxPre = pre;
            max = p;
        }
    }
    head->data = max->data;
    maxPre->next = max->next;
    free(max);
    return head;
}