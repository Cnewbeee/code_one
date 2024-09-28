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
    int n, m, k;
    cin >> n >> m >> k;
    if(m > n)m = n;
    if(m == 1 || k >= n-1){
        cout << "NO" << endl;
        return ;
    }

    int y = ceil((double)n / m);
    //cout << n-y << "<<" << k << endl;
    if(y == 1 && k < n-1){
        cout << "YES" << endl;
    }else if(n-y > k){
        cout << "YES" << endl;
    }else {
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
