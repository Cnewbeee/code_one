#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define INF 0x3f3f3f3f

int st[MAX_V] = {0};
int n, m, len;

int g[MAX_V][MAX_V];
int idl[MAX_V][MAX_V], dist[MAX_V], ans[MAX_V];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int prim() {
    int res = 0;

    int vl[MAX_V] = {0};
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 0; j < n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        if(i && dist[t] == INF)return INF;

        
        if(i){
            res += dist[t];
            ans[len++] = vl[t];
            //printf("%d %d\n", vl[t], dist[t]);
        }
        st[t] = 1;
        for(int j = 0; j < n; j++){
            if(st[j] || g[t][j] == INF)continue;
            if(dist[j] > g[t][j]){
                dist[j] = g[t][j];
                vl[j] = idl[t][j];
            }
            //printf("%d %d %d %d\n", t, j, g[t][j], dist[j]);
        }
    }

    return res;
}

int main() {
    int u, v, w, id;

    memset(g, INF, sizeof(g));
    memset(dist, INF, sizeof(dist));

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &id, &u, &v, &w);
        g[u][v] = w;
        g[v][u] = w;
        idl[u][v] = id;
        idl[v][u] = id;
        //printf("%d %d %d %d\n", id, u, v, g[u][v]);
    }

    int t = prim();
    printf("%d\n", t);
    qsort(ans, len, sizeof(int), cmp);
    
    for(int i = 0; i < len; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}