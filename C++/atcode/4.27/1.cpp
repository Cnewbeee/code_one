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
    int suma = 0, sumb = 0;
    for(int i = 0; i < 9; i ++){
        int t;
        cin >> t;
        suma += t;
    }
    for(int i = 0; i < 8; i++){
        int t;
        cin >> t;
        sumb += t;
    }
    cout << suma - sumb + 1 << endl;
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
