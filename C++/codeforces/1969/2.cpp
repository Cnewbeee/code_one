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
    int sum = 0, len = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){if(len != 1)sum += len;}
        else if(s[i] == '1'){len++;}
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
