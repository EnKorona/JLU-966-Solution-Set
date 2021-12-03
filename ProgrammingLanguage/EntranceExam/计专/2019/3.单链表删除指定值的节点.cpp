

ListNode* delete(ListNode* head,int x) {
    if(!head) return head;
    ListNode* cur = head;
    while(cur -> next) {
        if(cur -> next -> data == x) {
            cur -> next = cur -> next -> next;
        }
        cur = cur -> next;
    }
    return head;
}