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
    vector<int> c, a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c.push_back(a[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    map<int, int> ma;
    for(int i = 0; i < n+m; i++){
        ma[c[i]] = i+1;
    }
    for(int i = 0; i < n; i++)cout << ma[a[i]] << " ";cout << endl;
    for(int i = 0; i < m; i++)cout << ma[b[i]] << " ";cout << endl;
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
