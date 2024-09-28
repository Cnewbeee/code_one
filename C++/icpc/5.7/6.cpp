#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 500 + 10;
int n, m;
char g[N][N];
void solve()
{
    cin >> n >> m;
    int cnt[2] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            if(g[i][j] == '1')cnt[1]++;
            else cnt[0]++;
        }
    }
    if(cnt[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(cnt[0] == 0){
        cout << n * m / 2 << endl;
        return ;
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
