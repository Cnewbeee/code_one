#include <stdio.h>
#include <string.h>

const int maxn = 10010, maxe = 50010;
int n, m, cnt;
int head[maxn];
int in[maxn], topo[maxn];
int ve[maxn];
int vl[maxn];
int stack[maxn], top = -1; 
struct node {
    int to, next, w;
} e[maxe];

void add(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
    e[cnt++].w = w;
}

int TopoSort() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            stack[++top] = i; 
    while (top != -1) {
        int u = stack[top--]; 
        topo[cnt++] = u;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to;
            if (--in[v] == 0)
                stack[++top] = v; 
        }
    }
    if (cnt < n) return 0;
    return 1;
}

int CriticalPath() {
    if (TopoSort()) {
        printf("拓扑序列为：\n");
        for (int i = 0; i < n; i++)
            printf("%d\t", topo[i]);
        printf("\n");
    } else {
        printf("该图有环，无拓扑序列！\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        ve[i] = 0;
    for (int j = 0; j < n; j++) {
        int u = topo[j];
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            if (ve[v] < ve[u] + w)
                ve[v] = ve[u] + w;
        }
    }
    for (int i = 0; i < n; i++)
        vl[i] = ve[n - 1];
    for (int j = n - 1; j >= 0; j--) {
        int u = topo[j];
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            if (vl[u] > vl[v] - w)
                vl[u] = vl[v] - w;
        }
    }
    for (int i = 0; i < n; i++)
        printf("事件%d的最早发生时间和最迟发生时间：\n", i),
        printf("%d\t%d\n", ve[i], vl[i]);
    printf("关键活动路径为:\n");
    for (int u = 0; u < n; u++) {
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            int e = ve[u];
            int l = vl[v] - w;
            if (e == l)
                printf("<%d,%d>\n", u, v);
        }
    }
    return 1;
}

int main() {
    printf("请输入事件数量和活动数量：");
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    printf("请输入每个活动的起点、终点和权重：\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        in[v]++;
    }
    CriticalPath();
    return 0;
}
