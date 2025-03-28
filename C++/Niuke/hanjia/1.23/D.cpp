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
    string s;
    cin >> n >> s;
    s = '1' + s;
    int ans = 0;
    for(int i = 0; i < 26; i++){
        int pre = 0, las = 0;
        for(int j = 1; j <= n; j++){
            if(s[j] == 'a' + i){
                if(pre != 0){
                    ans = max(ans, n - j + 1);
                }
                pre = j;
            }
        }
        for(int j = n; j >= 1; j--){
            if(s[j] == 'a' + i){
                if(las != 0){
                    ans = max(ans, j);
                }
                las = j;
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
