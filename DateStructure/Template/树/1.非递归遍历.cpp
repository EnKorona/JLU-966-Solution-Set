/*
 * 先序：先出栈，右入栈，左入栈
 * 中序：左入栈顶头，头出指右子，再来一轮回
 * 后序：先出栈，左入栈，右入栈，后转置
 * 层序：先入队，左入队，右入队
 */


vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;
    stack < TreeNode * > stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        res.push_back(node->val);
        stk.pop();
        if (node->right != NULL) {
            stk.push(node->right);
        }
        if (node->left != NULL) {
            stk.push(node->left);
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;
    stack < TreeNode * > stk;
    TreeNode *cur = root;
    while (!stk.empty() || cur != NULL) {
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode *node = stk.top();
        res.push_back(node->val);
        stk.pop();
        if (node->right != NULL) cur = node->right;
    }
    return res;
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;
    stack < TreeNode * > stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *cur = stk.top();
        res.push_back(cur->val);
        stk.pop();
        if (cur->left != NULL) {
            stk.push(cur->left);
        }
        if (cur->right != NULL) {
            stk.push(cur->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vector <vector<int>> levelOrder(TreeNode *root) {
    vector <vector<int>> res;
    if (root == NULL) return res;
    queue < TreeNode * > q;
    q.push(root);
    while (!q.empty()) {
        int curLevelSize = q.size();
        vector<int> curLevel;
        for (int i = 0; i < curLevelSize; i++) {
            TreeNode *cur = q.front();
            curLevel.push_back(cur->val);
            q.pop();
            if (cur->left != NULL) {
                q.push(cur->left);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
            }
        }
        res.push_back(curLevel);
    }
    return res;
}