/*
 * 1. 用递归算法，递归判断v的子孙是否为u
 * 2. 递归出口：
 *      (1) L[v]或R[v]中存的是0,表示v节点没有子节点，返回错误
 *      (2) L[v]或R[v]中存的是u,表示u节点为v节点的子孙
 * 3. 如果L[v]和R[v]中的值都不为0和u，则递归判断其子节点的子节点是否
 */

int isChild(int L[], int R[], int u, int v) {
    if (v == 0) return false;
    if (v == u) return true;
    return isChild(L, R, u, L[v]) || isChild(L, R, u, R[v]);
}
