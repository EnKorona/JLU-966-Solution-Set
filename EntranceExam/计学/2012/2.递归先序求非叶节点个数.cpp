/*
 * 1. 采用递归先序遍历算法，如果root为空，则返回0，如果为叶节点也返回0
 * 2. 递归遍历求左右子树中的非叶节点个数，将其求和再加上当前节点，即为树中非叶节点个数
 */

int countNoLeaf(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 0;
    return 1 + countNoLeaf(root->left) + countNoLeaf(root->right);
}