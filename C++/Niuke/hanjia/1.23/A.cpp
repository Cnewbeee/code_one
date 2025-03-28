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
    for(int i = 0; i < 7; i++){
        int t;
        cin >> t;
        if(t != 1 && t!= 2 && t!= 3 && t!= 6 && t!= 5){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
