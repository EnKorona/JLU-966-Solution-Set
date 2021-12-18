
bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    if (leftDepth - rightDepth > 1 || leftDepth - rightDepth < -1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int getDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}