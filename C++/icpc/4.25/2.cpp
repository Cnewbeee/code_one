#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int h = max(x, y);
    int l = min(x, y);
    int b = k - h;
    int d = h - l;
    if(k < h){
        cout << -1 << endl;
        return ;
    }
    if(d % 2 == 1)k--;
    else if(b % 2 == 1)k-=2;
    cout << k << endl;
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
