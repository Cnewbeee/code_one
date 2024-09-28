#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 100 + 10;
int n;
int d[N];
int b[N][N];
int e[N], ne[N], h[N], idx;
queue<int> q;
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs(){
    for(int i = 0; i < n; i++){
        q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        cout << t << " ";
        q.pop();

        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j])b[t][j] = 1;
            d[j]--;
            //if(d[j] == 0)q.push(j);
        }
    }
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            int t;
            cin >> t;
            if(t == 1){
                d[j]++;
                //d[i]++;
                //cout << d[j] << ":" << j << endl;
                //add(i, j);
                //add(j, i);
            }
        }
    }
    //bfs();
    //cout << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            //cout << b[i][j] << " ";
            if(d[j] == 0)cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }

}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
