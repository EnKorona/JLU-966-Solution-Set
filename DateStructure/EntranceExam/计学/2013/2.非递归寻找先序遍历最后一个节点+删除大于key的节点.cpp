/*
 * 1. 若根节点为空，则直接返回
 * 2. 若有右孩子，则右孩子肯定在先序序列中当前节点之后；如果无右孩子，但有左孩子，则左孩子肯定在先序序列中当前节点之后；如果左右孩子皆无，则当前节点就是所求节点
 */

TreeNode *preLast(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *p = root;
    while (p != nullptr) {
        if (p->right != nullptr) p = p->right;
        else if (p->left != nullptr) p = p->left;
        else return p;
    }

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val == key) { //如果root的值为key
        if (root->left == nullptr) return nullptr; // 且左子树为空，则将这棵树全部删掉
        else return root->left; // 若左子树不为空，则左子树的值全部小于key，直接将左子树返回即可
    }
    if (root->val > key) { // 如果root的值大于key
        root->left = deleteNode(root->left, key);    //则将左子树中大于key的部分删除
        root->right = nullptr;    //直接将右子树删除
    }
    if (root->val < key) { // 如果root的值小于key
        root->right = deleteNode(root->right, key);  //则将右子树中大于key的部分删除
    }
}