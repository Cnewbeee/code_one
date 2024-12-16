#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = N<<1;

int n, h[N], ne[M], e[M], idx, st[N], ans = N;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    st[u] = 1;
    int sum = 1, res = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main(){

    memset(h, -1, sizeof(h));

    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}