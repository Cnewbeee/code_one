#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, m, d;
vector<int> a;
map<int, int> b;
bool cmp(int a, int b){
    return a > b;
}
void solve()
{
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    for(int j = 0; j < m; j++){
        int t;
        cin >> t;
        b[t]++;
    }
    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < n; i++){
        for(int j = d; j >= -d; j--){
            if(b[a[i]+j]){cout << 2 * a[i] + j << endl;return ;}
        }
    }
    cout << -1 << endl;
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
