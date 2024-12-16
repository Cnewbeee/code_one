#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int e[N], ne[N], h[N], idx;
int d[N], q[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort(){
    int tt = -1, hh = 0;

    for(int i = 1; i <= n; i++){
        if(!d[i]){
            q[++tt] = i;
        }
    }

    while(tt >= hh){
        int t = q[hh++];

        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]) q[++tt] = j;
        }
    }
    return tt == n-1;
}

int main(){
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }

    if(topsort()){
        for(int i = 0; i < n; i++){
            cout << q[i] << ' ';
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;

}
