#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
//int a[N];
map<int, int> m;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    m.clear();
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        m[t]++;
        if(m[t] == 2){
            ans++;
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
