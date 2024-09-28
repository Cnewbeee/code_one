#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int, int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int x = 1;
    for(int &i : v){
        cin >> i;
        x = lcm(x, i);
    }
    auto it = find(v.begin(), v.end(), x);
    if(it == v.end()){
        cout << n << endl;
        return ;
    }

    int ans = 0;
    auto cmd = [&](int d){
        if(find(v.begin(), v.end(), d) != v.end()){
            return ;
        }
        int cnt = 0, l = 1;
        for(int i = 0; i < n; i++){
            if(d % v[i] == 0){
                l = lcm(l, v[i]);
                cnt++;
            }
        }
        if(l == d)ans = max(ans, cnt);
    };

    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            cmd(i);
            cmd(x / i);
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
