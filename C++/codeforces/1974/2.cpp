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
    int n;
    cin >> n;
    cin >> s;
    set<char> se;
    for(int i = 0; i < n; i++){
        se.insert(s[i]);
    }
    string r;
    for(char i : se){
        r.push_back(i);
    }
    map<char, char> ma;
    int len = r.size();
    for(int i = 0; i < len; i++){
        ma[r[i]] = r[len-i-1];
    }
    for(int i = 0; i < n; i++){
        s[i] = ma[s[i]];
    }
    cout << s << endl;
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
