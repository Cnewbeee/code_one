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
    int x, y;
    cin >> x >> y;
    int ans = 0;
    int l = 0, r = 0;
    l = (y+1) / 2;
    r = l * 7;
    if(y % 2 == 1)r += 4;
    if(r >= x){
        ans = l;
    }else{
        ans = l;
        x -= r;
        ans += (x+14)/15;
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
