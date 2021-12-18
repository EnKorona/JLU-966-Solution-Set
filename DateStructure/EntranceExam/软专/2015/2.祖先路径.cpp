void postorder(TreeNode *root, TreeNode *p) {
    if (root == nullptr) return;
    stack < TreeNode * > stk;
    stack<int> ans;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *cur = stk.top();
        ans.push(cur->val);
        if (cur == p) {
            break;
        }
        stk.pop();
        if (cur->left != nullptr) {
            stk.push(cur->left);
        }
        if (cur->right != nullptr) {
            stk.push(cur->right);
        }
    }
    while (!ans.empty) {
        printf("%d ", ans.top()->data);
        s.pop();
    }
}