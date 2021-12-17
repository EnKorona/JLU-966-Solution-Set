/*
 * 邻接表
 */
struct ArcNode { // 边表节点
    int adjvex; // 邻接点域，存储该顶点对应的下标
    int weight; // 权值
    ArcNode *nextArc; // 链域，指向下一个邻接点的指针
}

struct VNode { // 顶点表节点
    int data; // 顶点域，存储顶点信息
    ArcNode *firstArc; // 边表头指针
}

struct Graph {
    VNode adjlist[]; // 图中顶点的数组
    int vexnum, arcnum; // 图中的顶点数和弧数
}


void bfs(Graph g, int v) {
    visit[v] = 1;
    queue <VNode> q;
    q.push(g->adjlist[v]);
    while (!q.empty()) {
        VNode cur = q.front();
        q.pop();
        ArcNode *p = cur.firstArc;
        while (p != nullptr) {
            if (!visit[p->adjvex]) {
                visit[p->adjvex] = 1;
                q.push(g->adjlist[p->adjvex]);
            }
        }
        p = p->nextArc;
    }
}