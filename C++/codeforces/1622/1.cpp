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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a+3);
    if((a[0] == a[1] && a[2] % 2 == 0)||(a[0] == a[2] && a[1] % 2 == 0)||(a[1] == a[2] && a[0] % 2 == 0)){
        cout << "YES" << endl;
    }
    else if(a[0] + a[1] == a[2]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
    cin >> t;

    while (t -- ){
        solve();
    }

	return 0;
}
