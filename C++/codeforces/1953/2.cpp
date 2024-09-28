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
    set<char> se;
    int l;
    for(int i = 0; i < s.size(); i++){
        se.insert(s[i]);
        if(s[i] != s[0])l = i;
    }
    if(se.size()-1){
        cout << "YES" << endl;
        swap(s[0], s[l]);
        cout << s << endl;
    }else{
        cout << "NO" << endl;
    }
    
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
