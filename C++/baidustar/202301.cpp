#include<bits/stdc++.h> 

using namespace std;

#define N 40010
int te, fe, s, t, f, n, m, ans = 1e9;
int kt[N], kf[N], kn[N], v[N];
vector<int> a[40010];
void bfs(int st, int r, int arr[]){
    v[st]++;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : a[x]){
            if(v[y] == r)continue;
            arr[y] = arr[x] + 1;
            v[y]++;
            q.push(y);
        }
    }
}
int main( )
{
    cin >> te >> fe >> s;
    cin >> t >> f >> n >> m;
    while(m--){
        int k, v;
        cin >> k >> v;
        a[k].push_back(v);
        a[v].push_back(k);
    }
    bfs(n, 1, kn);
    if(!v[t] || !v[f]){
        cout << -1 << endl;
        return 0;
    }
    bfs(t, 2, kt);
    bfs(f, 3, kf);

    for(int i = 1; i <= n; i++){
        if(v[i]){
            ans = min(ans, kf[i] * fe + kt[i] * te + kn[i] * (te + fe - s));
        }
    }
    cout << ans << endl;
    return 0;
}