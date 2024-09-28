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
    int a[n], b[n];
    int ans = 0;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];
    for(int i = 0, j = 0; i < n && j < n;){
        if(b[i] < a[j]){
            ans++;
            i++;
        }else{
            i++;
            j++;
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
