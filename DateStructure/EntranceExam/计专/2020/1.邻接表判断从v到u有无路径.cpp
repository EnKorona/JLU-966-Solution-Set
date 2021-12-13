struct ArcNode {
    int adjVex;
    int weight;
    ArcNode *nextArc;
}
struct VNode {
    int data;
    ArcNode *firstArc;
}
struct Graph {
    VNode vexList[];
    int vexnum, arcnum;
}

bool find(int v, int u) {
    ArcNode *p = g->vexList[v].firstArc;
    while (p != nullptr) {
        if (p->adjVex == u) return true;
        p = p->nextArc;
    }
    return false;
}