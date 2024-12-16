#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510, INF = 0x3f3f3f3f;

int n, m;
int g[MAXN][MAXN];
int st[MAXN];
int dist[MAXN];

int prim(){
    int res = 0;

    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t])) 
                t = j;

        if(i && dist[t] == INF) return INF;

        if(i) res += dist[t];

        //printf("%d , %d\n", res, t);

        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], g[t][j]);
        }

        st[t] = 1;
    }

    return res;
}

int main(){
    cin >> n >> m;

    memset(g, INF, sizeof(g));
    memset(dist, INF, sizeof(dist));

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
        //printf("%d ______\n", g[u][v]);
    }

    int ans = prim();

    if(ans == INF)puts("impossible");
    else cout << ans << endl;    

    return 0;
}