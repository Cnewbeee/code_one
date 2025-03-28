#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

// #define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve() {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    
    if(n < m){
        swap(n, m);
        swap(a, b);
    }

    int sum = 0, ans = 0;

    map<int, int> mp;

    for(char c : a)mp[c-'a']++;

    for(char c : b){
        if(mp[c-'a'] > 0)mp[c-'a']--;
        else sum++;
    }
    for(auto [x, y] : mp)
        if(y & 1)ans++;

    if(sum >= ans)ans = sum;
    else ans -= sum, ans /= 2, ans += sum;

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
