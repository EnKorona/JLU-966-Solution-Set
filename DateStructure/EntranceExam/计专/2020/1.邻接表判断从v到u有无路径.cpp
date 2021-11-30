
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
    int vexnum,arcnum; // 图中的顶点数和弧数
}

// v为起点，u为终点
bool find(int v,int u) {
    ArcNode *p = g -> vecList[v].firstArc; // p指向第一个邻接点
    while(p != nullptr) {
        if(p -> adjVex == u) return true;
        p = p -> nextArc;
    }
    return false;
}