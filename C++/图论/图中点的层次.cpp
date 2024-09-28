#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;
int d[N], q[N];
int m, n;
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(){
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = 1;
    d[1] = 0;

    while(hh <= tt){
        int t = q[hh++];

        for(int i = h[t]; i != -1; i = ne[i]){
            int p = e[i];
            if(d[p] == -1){
                d[p] = d[t] + 1;
                q[++tt] = p;
            }
        }
    }
    return d[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
}