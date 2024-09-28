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
    int a, b, c;
    ll sum = 0;
    cin >> a >> b >> c;
    sum = a + b + c;

    if(sum == 0){
        cout << 0 << endl;
        return ;
    }else if(sum % 2 == 1){
        cout << -1 << endl;
        return ;
    }
    int ans = 0;
    
    while(1){
        if(a == 0){
            ans += min(b, c);
            break;
        }
        if(b > c){
            swap(b, c);
        }
        a--, c--, ans++;
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
