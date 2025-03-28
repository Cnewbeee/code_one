#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int ans = 0;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ans = 0;
    
    if(n == 1){
        if(s == "?")cout << 2 << endl;
        else cout << 1 << endl;
        return;
    }

    int cnt = ranges::count(s, '?');
    int num = 1;
    for(int i = 1; i <= cnt; i++){
        num *= 2;
        num %= mod;
    }
    int num1 = 1;
    for(int i = 1; i < cnt; i++){
        num1 *= 2;
        num1 %= mod;
    }
    int sum = 0;
    if(s[0] != '?' && s[n-1] != '?'){
        if(s[0] == s[n-1])sum = 1ll * (n-2) * num % mod;
        else sum = 1ll *  2 * num % mod;
    }else{
        sum = 1ll * n * num1 % mod;
    }

    cout << sum << endl;
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
