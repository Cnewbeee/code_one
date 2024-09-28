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
    string s;
    cin >> s;
    if(s[0] == s.back()){
        cout << 0 << endl;
        return ;
    }

    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i+1]){
            cout << i + 1 << endl;
            return ;
        }
    }
    
    cout << -1 << endl;
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
