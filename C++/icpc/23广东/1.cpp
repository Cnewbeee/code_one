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
    int y1;
    cin >> y1;
    int n;
    cin >> n;
    vector<int> m(n);
    for(int &i : m)cin >> i;
    int y2;
    cin >> y2;
    int ans = y2 - y1 + 1;
    for(int i : m){
        if(i >= y1 && i <= y2)ans--;
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
