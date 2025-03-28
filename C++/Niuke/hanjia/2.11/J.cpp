#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int dc(int a, int n){
    if(n >= a) return (a + 1) * a / 2;
    else return (a + (a - n + 1)) * n / 2;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;
    
    for(int i = 1; i <= min(n, y); i++){
        int cd = x + i;
        int sum = 0;
        sum = cd * (min(n, y) - i + 1);
        if(n > y) sum += dc(cd-1, n-y);
        ans = max(ans, sum);
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
