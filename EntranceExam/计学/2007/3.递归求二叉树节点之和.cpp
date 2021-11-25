
int getSum(TreeNode *root) {
    if (root == nullptr) return 0;
    return root->val + root->left + root->right;
}