#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    string a;
    cin >> n >> a;
    
    int ans = 0, v = 0, v1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0'){
            if(v1 != v) v = v1;
            v += 10;
            v1 = v;
        }else if(a[i] == '1'){
            if(v1 != v) v = v1;
            if(v >= 5)v -= 5;
            else v = 0;
            v1 = v;
        }else{
            if(v1 == v){
                if(v >= 10)v -= 10;
                else v = 0;
            }
        }
        ans += v;
    }
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    // cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
