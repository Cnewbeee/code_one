#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100 + 10;
char a[N][N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    PII ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char t;
            cin >> t;
            if(a[i][j] != t){
                ans = {i+1, j+1};
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
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
