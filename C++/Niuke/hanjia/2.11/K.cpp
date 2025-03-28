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
    if(y % 2 == 0){
        cout << "NO" << endl;
        return;
    }
    int z = y / 2;
    if(x % 2 == z % 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
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
