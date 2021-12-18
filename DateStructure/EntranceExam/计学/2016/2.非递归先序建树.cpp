
TreeNode *build(int s[], int n) {
    if (n == 0) return nullptr;
    TreeNode *root = new TreeNode();
    stack < TreeNode * > stk;
    stk.push(root);
    for (int i = 0; i < n; i++) {
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            if (s[i] == 0) {
                cur->left == nullptr;
                cur->right == nullptr;
            }
            if (s[i] == 1) {
                cur->left = new TreeNode();
                cur->right = nullptr;
                stk.push(cur->left);
            }
            if (s[i] == 2) {
                cur->left = new TreeNode();
                cur->right = new TreeNode();
                stk.push(cur->left);
                stk.push(cur->right);
            }
        }
    }
    return root;
}