

struct ListNode {
    int data;
    ListNode* next;
}

void insert(ListNode head) {
    ListNode *left = head->next;
    ListNode *right = left->next;
    while (right != nullptr) {
        ListNode *inNode = new ListNode();
        inNode->data = left->data + right->data;
        inNode->next = right;
        left->next = inNode;
        left = right;
        right = left->next;
    }
}