/*
 * 1. 采用层次遍历，初始化队列，将根节点入队，初始化最大宽度为-1
 * 2. 当队列非空时，求出队列长度，即为当前层的节点个数，然后更新二叉树宽度
 * 3. 对队列中的元素执行出队操作，若其左右子树不为空则依次入队
 * 4. 反复执行2-3，直至队列清空
 */

struct TreeNode{
    int data;
    struct TreeNode *left,*right;
};

struct TreeNode* create(int S[], int n) {
    if(n == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* p = root;
    int i = 0;top = -1;
    struct TreeNode* stack[maxnum];
    while(i<n) {
        if(p != NULL) {
            if(S[i] == 0) {
                p -> left = NULL;
                p -> right = NULL;
            }
            if(S[i]==1) {
                struct TreeNode* temp = (struct TreeNode*) malloc(sizeof(struct TreeNode));
                p -> left =temp;
                p -> right = NULL;
            }
            if(S[i]==2) {
                struct TreeNode* temp1 = (struct TreeNode*) malloc(sizeof(struct TreeNode));
                struct TreeNode* temp2 = (struct TreeNode*) malloc(sizeof(struct TreeNode));
                p -> left =temp1;
                p -> right = temp2;
            }
            stack[++top] = p;
            p = p -> left;
            i++;
        }
        else {
            p = stack[top--];
            p = p -> right;
        }
    }
    return root;
}

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

TreeNode* preOrderCreateTree(int S[],int n) {
    if(n == 0) return NULL;
    TreeNode *root = new TreeNode();
    stack<TreeNode*> stk;
    stk.push(root);
    for (int i = 0;i< n;i++) {

    }
}
