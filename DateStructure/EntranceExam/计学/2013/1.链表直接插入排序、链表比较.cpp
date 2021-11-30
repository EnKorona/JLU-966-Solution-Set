/*
 * 1. 分别对链表f和g按照x的幂次进行直接插入排序，设置指针p和q分别指向两个链表
 * 2. 两个链表同时从表头向后遍历，进行比较。对应节点相等的条件为p -> exp -1 == q -> exp 且 p -> exp * p -> coef == q -> coef，若对应节点不相等则直接返回false
 * 3. 如果f的幂次为0，则将其跳过
 * 4. 若循环结束两个指针同时为空，则返回true，否则返回false
 * 【leetcode】0905
 */

struct ListNode {
    int coef;
    int exp;
    ListNode* next;
}

ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr) {
        return head;
    }
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *lastSorted = head;
    ListNode *curr = head->next;
    while (curr != nullptr) {
        if (lastSorted->exp <= curr->exp) {
            lastSorted = lastSorted->next;
        } else {
            ListNode *prev = dummyHead;
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return dummyHead->next;
}

bool isEqual(ListNode* f,ListNode* g) {
    ListNode*p = insertionSortList(f),*q = insertionSortList(g);
    if(p -> exp == 0) p = p -> next;
    while( p != nullptr && q != nullptr) {
        if(p -> exp -1 != q -> exp || p -> exp * p -> coef != q -> coef) return false;
        p = p -> next;
        q = q -> next;
    }
    if (p == nullptr && q == nullptr) return true;
    return false;
}