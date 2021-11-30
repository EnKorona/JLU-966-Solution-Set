struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
}


TreeNode buildTree(string s) {
    int len = s.length();
    stack < TreeNode * > stk;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            TreeNode *p = new TreeNode();
            p->left = nullptr;
            p->right = nullptr;
            s.push(p);
        }
        if (s[i] == '1') {
            TreeNode *p = new TreeNode();
            p->left = s.top();
            s.pop();
            p->right = nullptr;
            s.push(p);
        }
        if (s[i] == '2') {
            TreeNode *p = new TreeNode();
            p->left = s.top();
            s.pop();
            p->right = s.top();
            s.pop();
            s.push(p);
        }
    }
    return s.top();
}