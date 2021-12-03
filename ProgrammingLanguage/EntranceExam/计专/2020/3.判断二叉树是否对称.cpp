
bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return judgeSymmetric(root->left, root->right);
}

bool judgeSymmetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
        return true;
    } else if (left == nullptr || right == nullptr) {
        return false;
    } else if (left->val != right->val) {
        return false;
    } else {
        return judgeSymmetric(left->left, right->right) && judgeSymmetric(left->right, right->left);
    }
}