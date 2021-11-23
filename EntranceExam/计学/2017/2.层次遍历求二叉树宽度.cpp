/*
 * 1. 采用层次遍历，初始化队列，将根节点入队，初始化最大宽度为-1
 * 2. 当队列非空时，求出队列长度，即为当前层的节点个数，然后更新二叉树宽度
 * 3. 对队列中的元素执行出队操作，若其左右子树不为空则依次入队
 * 4. 反复执行2-3，直至队列清空
 */

int width(TreeNode *root) {
    if (root == nullptr) return 0;
    int maxWidth = -1;
    queue < TreeNode * > q;
    q.push(root);
    while (!q.empty()) {
        int curWidth = q.size();    //求出当前层的元素个数
        maxWidth = maxWidth > curWidth ? maxWidth : curWidth;   //更新二叉树宽度
        for (int i = 0; i < curWidth; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
    return maxWidth;
}