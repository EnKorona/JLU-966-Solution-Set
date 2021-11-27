/*
 * 1. 采用层次便利，初始化最大宽度为0，初始化队列，将根节点入队
 * 2. 用curLevelSize表示当前层的节点个数，当curLevelSize的值大于max时，将max更新
 * 3. 反复执行出队，并将左右节点入队，重复2，直到队列中元素全部出队
 * 【leetcode】类似0102
 */

int levelOrder(TreeNode *root) {
    int max = 0;
    if (root == nullptr) return 0;
    queue < TreeNode * > q;
    q.push(root);
    while (!q.empty()) {
        int curLevelSize = q.size();
        max = curLevelSize > max ? curLevelSize : max;
        for (int i = 0; i < curLevelSize; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
    }
    return max;
}