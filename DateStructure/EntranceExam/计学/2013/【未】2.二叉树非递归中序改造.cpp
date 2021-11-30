/*
 * 1. 若根节点为空，则直接返回
 * 2. 若有右孩子，则右孩子肯定在先序序列中当前节点之后；如果无右孩子，但有左孩子，则左孩子肯定在先序序列中当前节点之后；如果左右孩子皆无，则当前节点就是所求节点
 */

TreeNode *preLast(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *p = root;
    while (1) {
        if (p->right != nullptr) p = p->right;
        else if (p->left != nullptr) p = p->left;
        else return p;
    }

    -------------------------------------
    下方未修改
    void Del(struct TreeNode* root) {
        if(root != NULL) {
            Del(root -> left);
            Del(root -> right);
            free(root);
        }
    }

    void DelX(TreeNode* root,int x) {
        TreeNode* queue[maxnum];
        int front = -1,rear = -1;
        TreeNode* p = root,*pre = NULL;
        while(p -> right != NULL && p -> val <= x) {
            pre = p;
            p = p -> right;
        }
        if(p -> val <=x) {
            return;
        }
        queue[++rear] = p; // 将节点p入队
        while(front != rear) {
            p = queue[++front]; //出队
        }
        if(p -> val <=x)
            queue[++rear] = p -> right;
        else {
            if(p ->left != NULL) {
                queue[++rear] = p -> left;
                pre -> right = p -> left;
                p -> left = NULL;
                Del(p);
            }
        }
    }