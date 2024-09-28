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
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i : v){
        cin >> i;
    }
    string a;
    cin >> a;

    map<int, int> l, r;
    for(int i = 0; i < n; i++){
        if(a[i] == '0')r[v[i]] = 0;
        else l[v[i]] = 0;
    }
    int p = 1;
    for(auto &[x, y] : r){
        y = p++;
    }
    for(auto &[x, y] : l){
        y = p++;
    }
    for(int i = 0; i < n; i++){
        if(r.count(v[i]))cout << r[v[i]] << " ";
        else cout << l[v[i]] << " ";
    }
    cout << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
    cin >> t;

    while (t -- ){
        solve();
    }

	return 0;
}
