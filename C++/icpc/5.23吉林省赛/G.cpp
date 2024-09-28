#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool cmp(pair<int, PII> a, pair<int, PII> b){
    if(a.first == b.first){
        return a.second.second < b.second.second;
    }else{
        return a.first > b.first;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, PII>> t(n);
    for(int i = 0; i < n; i++){
        int l, r, h;
        cin >> l >> r >> h;
        t[i].first = h, t[i].second = {l, r};
    }
    int x, y;
    cin >> x >> y;
    sort(t.begin(), t.end(), cmp);
    //for(auto i : t)cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    int ans = x;
    for(auto i : t){
        if(i.first - y <= 0 && i.second.first - ans < 0 && i.second.second - ans >= 0)
            ans = i.second.second;
    }
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
