struct ArcNode {
    int adjvex;
    int weight;
    ArcNode *nextArc;
}

struct VNode {
    int data;
    int dist;
    ArcNode *firstArc;
}

struct Graph {
    VNode adjlist[MAXN];
    int vexnum, arcnum;
}

int visit[MAXN];

int BFS(Graph g, int v, int u) {
    for (int i = 0; i < g->vexnum; i++) {
        g->adjlist[i].dist = 0;
    }
    queue <VNode> q;
    visit[i] = 1;
    q.push(g->adjlist[v]);
    while (!q.empty()) {
        VNode cur = q.front();
        q.pop();
        ArcNode *p = cur->firstArc;
        while (p != nullptr) {
            if (p->adjvex != u) {
                if (visit[p->adjvex] == 0) {
                    visit[p->adjvex] = 1;
                    g->adjlist[p->adjvex].dist = cur.dist + 1;
                    q.push(g->adjlist[p->adjvex]);
                } else {
                    return p.dist;
                }
            }
            p = p->nextArc;
        }
    }
}


int GetMax(Graph g) {
    int max = 0, temp = 0;
    for (int i = 0; i < g->vexnum; i++) {
        for (int j = i + 1, j<g->vexnum, j++) {
            temp = BFS(g, i, j);
            max = max > temp ? max : temp;
        }
    }
    return max;
}