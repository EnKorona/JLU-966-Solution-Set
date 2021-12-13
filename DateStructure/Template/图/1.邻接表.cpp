/*
 * 邻接表
 */
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
