TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val == key) {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode *rightMin = getMin(root->right);
        root->val = rightMin->val;
        root->right = deleteNode(root->right, key);
    }
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

TreeNode *getMin(TreeNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}