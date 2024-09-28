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

    cin >> m >> n;
    int a[7] = {0};
    for(int i = 0; i < m; i++){
        char t;
        cin >> t;
        a[int(t-'A')]++;
    }
    int ans = 0;
    for(int i = 0; i < 7; i++){
        //cout << a[i] << endl;
        if(a[i] < n){
            ans += (n - a[i]);
            //cout << char(i+'A') << " " << int(a[i]) << endl;
        }
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
