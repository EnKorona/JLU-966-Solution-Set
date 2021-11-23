/*
 * 1. 采用递归先序遍历，递归求出每个节点左右子树的高度，得到树的高度返回
 * 2. 设置全局变量数组count[MAXSIZE],用于统计各层独生叶节点的个数
 * 3. 在递归的过程中判断每个节点的左右子节点是否为独生叶节点，并将其统计
 * 4. 递归完成后，用for循环输出每层的独生叶节点个数
 * 【leetcode】类似1469
 */

int count[MAXSIZE] = {0};

int countLeafNoBrotherNode(TreeNode *root, int i) {  // 递归函数传入根root，和当前节点所在的层数i，返回以root为根的树的高度
    if (root == nullptr) return 0;
    if (!root->left && root->right && !root->right->left && !root->right->right)
        cnt[i + 1]++; // 如果左子树为空，右子树不为空，且右子树为叶节点，则右子树为独生叶节点
    if (!root->right && root->left && !root->left->left && !root->left->right) cnt[i + 1]++;
    // 递归调用左右子树，返回左右子树的树高度
    int leftMaxDepth = countLeafNoBrotherNode(root->left, i + 1);
    int rightMaxDepth = countLeafNoBrotherNode(root->right, i + 1);
    return 1 + leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth;
}

void countLeaf(TreeNode *root) {
    int depth = countLeafNoBrotherNode(root, 1);
    for (int i = 1; i <= depth; i++) {
        printf("第%d层有%d个独立叶节点", i, count[i]);
    }
}