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
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s) mp[c]++;
    int ans = 1;
    if(mp['c'] == 1 && mp['d'] == 1 && mp['e'] == 1 && mp['n'] == 1 && mp['o'] == 2 && mp['r'] == 1 && mp['w'] == 1 && s.length() == 8){
        cout << "happy new year" << endl;
    }else{
        cout << "I AK IOI" << endl;
    }
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
