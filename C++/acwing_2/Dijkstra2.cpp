#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int N = 1000010;
int e[N], w[N], ne[N], h[N], idx;
int dist[N];
bool vis[N];
int n, m;
priority_queue<PII, vector<PII>, greater<PII>> pq;

void Add(int u, int v, int ww) {
    e[idx] = v;
    w[idx] = ww;
    ne[idx] = h[u];
    h[u] = idx++;
}

int Dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        PII u = pq.top();
        pq.pop();
        int ver = u.second;
        if (vis[ver]) continue;
        vis[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j =  e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        Add(a, b, c);
    }

    cout << Dijkstra() << endl;
    return 0;
}