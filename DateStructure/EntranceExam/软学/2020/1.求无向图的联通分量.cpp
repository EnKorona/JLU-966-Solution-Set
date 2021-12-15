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
    VNode adjlist[MAXN];
    int vexnum, arcnum;
}

void dfs(Graph g, int v, int visit[]) {
    visit[v] = 1;
    ArcNode *p = g.adjlist[v].firstArc;
    while (p != nullptr) {
        if (!visit[p->adjVex]) {
            dfs(g, p->adjVex, visit);
        }
        p = p->next;
    }
}

int component(Graph g) {
    int ans = 0;
    int visit[g->vexnum] = new int();
    memset(visit, 0, sizeof(int) * (vexnum + 1));
    for (int i = 0; i < g->vexnum; i++) {
        if (!visit[i]) {
            dfs(g, i, visit);
            ans++;
        }
    }
    return ans;
}