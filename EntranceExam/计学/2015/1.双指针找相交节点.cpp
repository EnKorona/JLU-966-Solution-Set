/*
 * 1. 指针p1指向第一个链表的头节点，p2指向第二个链表的头节点，两者同时向后遍历
 * 2. 当其中一个链表走到链表尾时，将其指向另一个链表的头节点，继续向后遍历
 *    (1) 当p1=p2不为空时，所指向的就是链表相交的交点
 *    (2) 当p1=p2且为nullptr时，即转向之后又同时遍历到了链表尾，则说明二者不相交
 * 【leetcode】0160
 */

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    ListNode *p1 = head1, *p2 = head2;
    while (p1 != p2) {
        p1 = p1 == nullptr ? head2 : p1->next;
        p2 = p2 == nullptr ? head1 : p2->next;
    }
    return p1;
}