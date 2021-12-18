DListNode {
    int data, freq;
    DListNode *llink;
    DListNode *rlink;
};

DListNode *Locate(DListNode *head, int x) {
    DListNode *p = head;
    while (p != nullptr && p->data != x) {
        p = p->rlink;
    }
    if (p != nullptr) p->freq++;
    q = p->llink;
    while (q != head && q->freq < p->freq) {
        q = q->llink;
    }
    p->llink->rlink = p->rlink;
    p->rlink->llink = p->llink;
    p->llink = q;
    p->rlink = q->rlink;
    q->rlink = p;
    return head;
}