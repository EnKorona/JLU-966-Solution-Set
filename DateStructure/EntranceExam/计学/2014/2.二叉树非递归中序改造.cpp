/*
 * 1. 采用类似中序遍历序列的访问，先访问右子树，再访问根节点，最后访问左子树，即可以得到递减顺序
 * 2. 遍历每个节点的过程中，判断其是否左子树非空，右子树为空，则将其输出
 * 【leetcode】类似0094
 */

void inOrderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    stack < TreeNode * > stk;
    TreeNode *cur = root;
    while (!stk.empty() || cur != nullptr) {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->right;
        }
        TreeNode *node = stk.top();
        stk.pop();
        if (p->left && !p->right) printf("%d/n", p->data);
        p = p->left;
    }
}