TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *root = baseBuild(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    return root;
}

TreeNode *baseBuild(vector<int> &inorder, vector<int> &postorder, int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight) return NULL;

    int inRootIdx = -1;
    for (int i = inLeft; i < inorder.size(); i++) {
        if (inorder[i] == postorder[postRight]) {
            inRootIdx = i;
            break;
        }
    }
    int leftLen = inRootIdx - inLeft;

    TreeNode *root = new TreeNode();
    root->val = postorder[postRight];
    root->left = baseBuild(inorder, postorder, inLeft, inRootIdx - 1, postLeft, postLeft + leftLen - 1);
    root->right = baseBuild(inorder, postorder, inLeft + leftLen + 1, inRight, postLeft + leftLen, postRight - 1);
    return root;

}