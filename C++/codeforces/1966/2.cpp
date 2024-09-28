#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 500 + 10;
int n, m;
char a[N][N];
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        if(a[1][1] == a[1][m]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return ;
    }
    if(m == 1){
        if(a[1][1] == a[n][1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return ;
    }
    if(a[1][1] == a[n][m] || a[1][m] == a[n][1]){
        cout << "YES" << endl;
        return ;
    }
    if(a[1][1] == a[1][m]){
        for(int i = 1; i <= m; i++){
            if(a[n][i] == a[1][1]){
                cout << "YES" << endl;
                return ;
            }
        }
    }
    if(a[n][1] == a[n][m]){
        for(int i = 1; i <= m; i++){
            if(a[1][i] == a[n][1]){
                cout << "YES" << endl;
                return ;
            }
        }
    }
    if(a[1][1] == a[n][1]){
        for(int i = 1; i <= n; i++){
            if(a[i][m] == a[1][1]){
                cout << "YES" << endl;
                return ;
            }
        }
    }
    if(a[1][m] == a[n][m]){
        for(int i = 1; i <= n; i++){
            if(a[i][1] == a[1][m]){
                cout << "YES" << endl;
                return ;
            }
        }
    }
    cout << "NO" << endl;
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
