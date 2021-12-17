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

bool isEqual(ListNode* f,ListNode* g) {
    ListNode*p = insertionSort(f),*q = insertionSort(g);
    if(p -> exp == 0) p = p -> next;
    while( p != nullptr && q != nullptr) {
        if(p -> exp -1 != q -> exp || p -> exp * p -> coef != q -> coef) return false;
        p = p -> next;
        q = q -> next;
    }
    if (p == nullptr && q == nullptr) return true;
    return false;
}