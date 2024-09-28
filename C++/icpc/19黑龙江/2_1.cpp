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
    char t;
    string ss;
    for(int i = 0; i < s.size(); i++){
        t = s[i];
        ss.push_back(t);
        int p = ss.size()-1;
        if(p >= 2 && ss[p] == ss[p-1] && ss[p] == ss[p-2]){
            ss.erase(p-2);
        }
    }
    if(ss.empty()) cout << "NAN" << endl;
    else cout << ss << endl;
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
