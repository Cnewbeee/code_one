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
    int ans = -1;
    if(n == 2){
        cin >> v[0] >> v[1];
        cout << min(v[0], v[1]) << endl;
        return ;
    }
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i >= 2){
            int a = v[i-2], b = v[i-1], c = v[i];
            int k;
            if(a >= b && b >= c){
                k = b;
            }else if(a >= c && c >= b){
                k = c;
            }else if(b >= a && a >= c){
                k = a;
            }else if(b >= c && c >= a){
                k = c;
            }else if(c >= a && a >= b){
                k = a;
            }else if(c >= b && b >= a){
                k = b;
            }
            ans = max(ans, k);
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
