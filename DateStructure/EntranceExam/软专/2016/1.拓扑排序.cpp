struct ArcNode {
    int adjvex;
    int weight;
    ArcNode *nextArc;
}

struct VNode {
    int data;
    ArcNode *firstArc;
}

struct Graph {
    VNode adjlist[MAXN];
    int vexnum, arcnum;
}

bool Topo(Graph g) {
    stack <VNode> stk; //初始化栈，存储入度为0的顶点
    for (int i = 0; i < g.vexnum; i++) {
        if (indegree[i] == 0) {
            stk.push(i);    //将所有入度为0的顶点入栈
        }
        int count = 0;  //记录当前已输出的顶点数
        while (!stk.empty()) {   //若栈不空
            stk.pop();  //栈顶元素出栈
            printf("输出顶点%d", i);
            count++;
            for (p = adjlist[i].firstArc; p != nullptr; p = p->nextArc) {    //将所有指向i的顶点的入度减1
                VNode v = p->adjvex;
                if ((indegree[v]--) == 0) {  //如果入度减为0，则入栈
                    stk.push(v);
                }
            }
            if (count < g.vexnum) return false;  //拓扑排序失败，有向图中有回路
            else return true;  //拓扑排序成功
        }
