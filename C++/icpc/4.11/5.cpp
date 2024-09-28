#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
int a[25];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i != 1){
            a[i] = gcd(a[i], a[i-1]);
        }
    }
    cout << a[n] << endl;
    //gcd(4059, -1782)
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
