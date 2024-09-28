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
    int ans = 0, sum = 0;
    int a[n+1], r[n+2];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    r[n+1] = 9e9;
    for(int i = n; i >+ 1; i--){
        r[i] = min(a[i], r[i+1]);
    }
    for(int i = 1; i <= n; i++){
        sum++;
        if(a[i] == r[i]){
            ans += sum / a[i];
            sum -= int(sum/a[i])*a[i];
        }
    }
    cout << ans << endl;
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
