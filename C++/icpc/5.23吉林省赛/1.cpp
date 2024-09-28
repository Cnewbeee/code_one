#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int m[N];
int find(int x){
    if(m[x] != x)return m[x] = find(m[x]);
    else return m[x];
}
void solve()
{
    int n;
    cin >> n;
    PII p[n+1];
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    for(int i = 1; i <= n; i++){
        m[i] = i;
    }
    for(int i = 1; i <= n; i++){
        int ia = p[i].first, ib = p[i].second;
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            int ja = p[j].first, jb = p[j].second;
            if(ia - ja <= i - j && i - j <= ib - jb)m[j] = find(i);
            else if(ja - jb <= j - i && j - i <= jb - ja)m[j] = find(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(m[i] == i)ans++;
    }
    cout << ans << endl;
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
