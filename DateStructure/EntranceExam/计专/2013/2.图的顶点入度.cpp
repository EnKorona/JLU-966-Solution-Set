struct ArcNode { // 边
    int adjVex; // 邻接点在数组中的位置下标
    ArcNode *nextArc; // 指向下一个邻接点的指针
    int weight; // 权值
}

struct VNode { // 顶点
    int data; // 顶点的数据域
    ArcNode *firstArc; // 指向邻接点的指针
}

struct Graph {
    AdjList vexList[]; // 图中顶点的数组
    int vexnum, arcnum; // 图中的顶点数和弧数
}

void count(Graph p) {
    for (int i = 1; i <= g.vexnum; i++) {
        ArcNode *p = g.AdjList[i].firstArc;
        while (p != nullptr) {
            res[p->adjVex]++; // p指向的节点的入度+1
            p = p->nextArc;
        }
    }
}