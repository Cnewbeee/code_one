#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int C(int n, int m){
    int res = 1;
    int t = n;
    while(t >= n-m+1){
        res *= t--;
    }
    t = m;
    while(t > 1){
        res /= t--;
    }
    return res;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int v[n+1] = {0};

    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        int t[n+1] = {0};
        for(int j = 0; j < c; j++){
            int tt;
            cin >> tt;
            t[tt]++;
        }
        char r;
        cin >> r;
        if(r == 'o'){
            for(int j = 1; j <= n; j++){
                if(t[j] == 0){
                    v[j] = -1;
                }
            }
        }else{
            for(int j = 1; j <= n; j++){
                if(t[j] == 0 && v[j] == 0){
                    v[j] = 1;
                }
            }
        }
    }
    int cnt = 0, cnf = 0, cn = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] == 1)cnt++;
        else if(v[i] == -1)cnf++;
        else cn++;
    }
    cout << C(cn, k-cn) << endl;
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
