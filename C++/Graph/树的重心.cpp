#include<bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 2;

int e[M], h[N], ne[M], idx;
int n, ans = N, st[N];
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dfs(int u){
    st[u] = true;
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int p = e[i];
        if(st[p])continue;

        int s = dfs(p);
        //cout << size << ":::" << s << "::" << p << endl;
        size = max(size, s);
        sum += s;
    }

    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}
int main(){
    cin >> n;

    memset(h, -1, sizeof h);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;
}