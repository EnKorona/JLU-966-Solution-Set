struct ArcNode {
    int adjVex;
    int weight;
    ArcNode *nextArc;
}

struct VNode {
    int data;
    ArcNode *firstArc;
    int dist;
}

struct Graph {
    int adjList[MAXN];
    int vexnum, arcnum;
}


int visit[MAXN];

void BFS(Graph g, int v, int k) {
    for (int i = 0; i < g->vexnum; i++) {
        g->adjList[i].dist = 0;   //初始化所有节点的dist为0
    }
    queue <VNode> q; //建立队列用于BFS
    visit[v] = 1;   //标记起点已访问
    q.push(g->adjList[v]);    //当前节点已入队
    while (!q.empty()) { //如果队列不为空
        VNode cur = q.front();  //读取队头元素
        q.pop();    //对头元素出队
        ArcNode *p = cur.firstArc;  //p指向当前节点的第一个边节点
        while (p != nullptr) {
            if (visit[p->adjVex] == 0) {   //如果当前边节点未被访问
                visit[p->adjVex] = 1;  //访问当前节点
                g->adjList[p->adjVex].dist = cur.dist + 1;   //邻接节点dist等于当前节点dist+1
                q.push(g->adjList[p->adjVex]);  // 将邻接节点入队
                if (g->adjList[adjVex].dist == k) {    // 若当前节点距离等于k则输出
                    printf("%d", p->adjVex);
                }
            }
            p = p->nextArc;   //p指向下一个邻接节点
        }
    }
}