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
    int n, q;
    cin >> n >> q;
    int ans = -1;
    map<int, int> ma;
    for(int i = 1; i <= q; i++){
        int m;cin >> m;
        m--;
        int r = m % n, l = (m/n)+n;
        ma[r]++;
        ma[l]++;
        if((ma[r] >= n || ma[l] >= n) && ans == -1){
            ans = i;
        }
        if(m % n == m / n){
            ma[-1]++;
        }if(n - (m % n) - 1 == m / n){
            ma[-2]++;
        }
        if((ma[-1] >= n || ma[-2] >= n) && ans == -1){
            ans = i;
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
