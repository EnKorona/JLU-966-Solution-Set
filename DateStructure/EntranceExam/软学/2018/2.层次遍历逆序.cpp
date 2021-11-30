/*
 * 1. 用层次遍历算法，不过入队时将右子节点先入队，之后再将左子节点入队
 * 2. 出队后将节点入栈，直到队列为空时，所有节点均已入栈
 * 3. 将栈中节点依次出栈并输出
 */

void reverseLevelOrder(TreeNode *root) {
    if (root == nullptr) return;
    queue < TreeNode * > q;
    q.push(root);
    stack < TreeNode * > stk;
    while (!q.empty()) {
        int curLevelSize = q.size();
        for (int i = 0; i < curLevelSize; i++) {
            TreeNode *cur = q.front();
            q.pop();
            stk.push(cur);
            if (cur->right != nullptr) q.push(cur->right);
            if (cur->left != nullptr) q.push(cur->left);
        }
    }
    for (int i = 0; i < stk.size(); i++) {
        printf("%d", stk.top()->data);
        stk.pop();
    }
    return 0;
}