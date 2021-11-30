struct ListNode {
    char ch;
    ListNode *next;
}

bool isSubString(ListNode *A, ListNode *B) {
    ListNode posA = A;
    ListNode headB = B;
    while (A != nullptr && B != nullptr) {
        if (A->data == B->data) {
            A = A->next;
            B = B->next;
        } else {
            posA = pos->next;
            A = posA;
            B = headB;
        }
    }
    if (B == nullptr) return true;
    return false;
}