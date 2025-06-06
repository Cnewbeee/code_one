#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1000 + 10;
int dp[N], w[N], len;
string s[N];
map<string, int> a, b, c;
set<string> st;

void solve()
{
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        cin >> s[i];
        a[s[i]] += x;
        b[s[i]] = y;
        c[s[i]] = z;
        st.insert(s[i]);
    }
    
    for(string t : st){
        while(a[t] > c[t]){
            w[++len] = b[t] * c[t];
            a[t] -= c[t];
        }
        if(a[t] > 0){
            w[++len] = b[t] * a[t];
            a[t] = 0;
        }
    }

    m = 21 - m;

    for(int i = 1; i <= len; i++){
        for(int j = m; j > 0; j--){
            dp[j] = max(dp[j], dp[j-1] + w[i]);
        }
    }
    cout << dp[m] << endl;
    
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
