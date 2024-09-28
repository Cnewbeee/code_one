#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100 + 10;
//vector<vector<int>> v(N);
map<PII, int> ma;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        ma[{a, b}] ++;
        ma[{b, a}] ++;
    }
    int ans  = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].size() >= 2){
            for(int j = 1; j < v[i].size(); j++){
                if(ma[{v[i][j-1], v[i][j]}])continue;
                ans++;
                v[v[i][j]].push_back(v[i][j-1]);
                v[v[i][j-1]].push_back(v[i][j]);
                ma[{v[i][j-1], v[i][j]}]++;
                ma[{v[i][j], v[i][j-1]}]++;
                //cout << v[i][j-1] << " " << v[i][j] << endl;
            }
        }
    }
    cout << ans << endl;
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
