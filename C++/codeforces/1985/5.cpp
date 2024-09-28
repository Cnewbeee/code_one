#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool isp(int x){
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void solve()
{
    int n, m, o, v;
    cin >> n >> m >> o >> v;
    int ma = max(n, max(m, o));
    if(v == 1){
        cout << n * m * o << endl;
        return;
    }else if(v > n * m * o){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        if(v % i != 0){
            continue;
        }
        int s = v / i;
        if(s > m * o){
            continue;
        }
        for(int j = 1; j <= m; j++){
            if(s % j != 0){
                continue;
            }
            int t = s / j;
            if(t > o){
                continue;
            }
            int x = 1, y = 1, z = 1;
            x += n-i, y += m-j, z += o-t;
            if(x * y * z > ans && i * j * t == v){
                ans = x * y * z;
                //cout << i << " " << j << " " << t << endl;
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
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
