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
    string ans;

    char t;
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j++){
            cin >> t;
            if(t == '*'){
                ans.push_back(j+'a');
                ans.push_back(8-i+'0');
            }
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
