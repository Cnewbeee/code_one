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
    int l = 1;
    int r = 1;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i+1]){
            l++;
        }
        if(s[i] == '0' && s[i+1] == '1' && r){
            l--;r--;
        }
    }
    cout << l << endl;
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
