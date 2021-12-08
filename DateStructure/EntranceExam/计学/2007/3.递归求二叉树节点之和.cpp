
int getSum(TreeNode *root) {
    if (root == nullptr) return 0;
    return root -> val + getSum(root -> left) + getSum(root -> right);
}