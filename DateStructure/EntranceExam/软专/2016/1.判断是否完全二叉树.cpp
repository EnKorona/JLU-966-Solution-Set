bool isCompleteTree(TreeNode *root) {
    if (root == nullptr) return true;
    queue < TreeNode * > q;
    q.push(root);
    bool lastLevel = false;
    while (!q.empty()) {
        int curLevelSize = q.size();
        for (int i = 0; i < curLevelSize; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) {    //如果队列中出现空节点，就应该是到达最后一层节点了
                lastLevel = true;
                continue;
            } else {
                if (lastLevel) { //如果出现空节点后出现非空节点，就说明不是完全二叉树
                    return false;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }

    }
    return true;
}