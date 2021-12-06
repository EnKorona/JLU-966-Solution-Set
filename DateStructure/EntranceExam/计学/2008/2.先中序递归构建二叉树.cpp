/*
 * 1. 采用递归方式建树，先序遍历的第一个节点就是根节点
 * 2. 遍历中序序列，找到根节点所在位置inRootIdx，则左子树的长度即为inRootIdx - inleft
 * 3. 建立根节点，递归的构造左右子树，并连接到根节点
 * 【leetcode】0105
 */

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *root = baseBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return root;
}

TreeNode *baseBuild(vector<int> &preorder, vector<int> &inorder, int preleft, int preright, int inleft, int inright) {
    if (preleft > preright) return nullptr;

    int inRootIdx = -1;
    for (int i = inleft; i < inorder.size(); i++) {
        if (inorder[i] == preorder[preleft]) {
            inRootIdx = i;
            break;
        }
    }
    int leftLen = inRootIdx - inleft;
    TreeNode *root = new TreeNode();
    root->val = preorder[preleft];
    root->left = baseBuild(preorder, inorder, preleft + 1, preleft + leftLen, inleft, inRootIdx - 1);
    root->right = baseBuild(preorder, inorder, preleft + leftLen + 1, preright, inRootIdx + 1, inright);
    return root;
}