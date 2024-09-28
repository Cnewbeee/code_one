#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i : a)cin >> i;
    for(int &i : b)cin >> i;

    vector<PII> c(n+m);
    for(int i = 0; i < n; i++)c[i] = {a[i], 1};
    for(int i = 0; i < m; i++)c[i+n] = {b[i], 2};

    sort(c.begin(), c.end());

    for(int i = 0; i < n + m-1; i++){
        if(c[i].second == c[i+1].second && c[i].second == 1){
            cout << "Yes" << endl;
            return ; 
        }
    }
    cout << "No" << endl;
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
