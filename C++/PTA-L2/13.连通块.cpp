#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> pii;

int n, m, k;
pii road[N];
int f[N], flag[N];
int Find(int x){
    if(f[x] != x) return Find(f[x]);
    return f[x];
}
void join(int x, int y){
    int fx = Find(x), fy = Find(y);
    if(fx!= fy) f[fy] = fx;
}

int bf(){
    int res = 0;
    for(int i = 0; i < n; i++){
        f[i] = i;
    }
    for(int i = 0; i < m; i++){
        if(flag[road[i].first] == 0 && flag[road[i].second] == 0){
            join(road[i].first, road[i].second);
        }
    }
    for(int i = 0; i < n; i++){
        if(Find(i) == i && flag[i] == 0)res++;
    }
    return res;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        road[i] = pii(x, y);
    }
    cin >> k;
    int l = -1;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        l = bf();
        flag[x] = 1;
        if(bf() > l)cout << "Red Alert: City " << x << " is lost!" << endl;
        else cout << "City " << x << " is lost." << endl;
        if(i == n) cout << "Game Over." << endl;
    }

}