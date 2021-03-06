struct ArcNode { // 边表节点
    int adjVex; // 邻接点域，存储该顶点对应的下标
    int weight; // 权值
    ArcNode *nextArc; // 链域，指向下一个邻接点的指针
}

struct VNode { // 顶点表节点
    int data; // 顶点域，存储顶点信息
    ArcNode *firstArc; // 边表头指针
}

struct Graph {
    VNode vexList[]; // 图中顶点的数组
    int vexnum, arcnum; // 图中的顶点数和弧数
}
bool isTree(Graph g) {
    Enum = 0;   //记录边数
    Vnum = 0;   //记录顶点数
    int visit[MAXN] = new int();
    dfs(g, 1, Vnum, Enum, visit);
    if (Vnum == g.arcnum && Enum == 2 * (g.vexnum - 1)) return true;
    else return false;
}

void dfs(Graph g, int v, int &Vnum, int &Enum, int visit[]) {
    visit[v] = 1;
    Vnum++;
    ArcNode *p = g.vexList[v].firstArc;
    while (p != nullptr) {
        Enum++;
        if (!visit[p->adjVex]) {
            dfs(g, p->adjVex, Vnum, Enum, visit);
        }
        p = p->nextArc;
    }

}