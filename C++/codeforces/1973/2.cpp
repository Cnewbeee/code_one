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
    vector<int> v(n);
    int ans = 1;
    int res = 0;
    for(int &i : v)cin >> i, res |= i;
    for(int i = 0; i <= 20; i++){
        int las = -1;
        int falg = 0;
        for(int j = 0; j < n; j++){
            if((v[j]>> i) & 1){
                ans = max(ans, j - las);
                las = j;
                falg = 1;
            }
        }
        if(falg){
            ans = max(ans, n-las);
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
