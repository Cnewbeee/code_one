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
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int cn = 0;
    map<int, int> ma;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(a[i] != b[i])cn++; 
        ma[b[i]]++;
    }
    //cout << cn << endl;
    int m;
    cin >> m;
    map<int, int> se;
    int t;
    int d[m];
    for(int i = 0; i < m; i++){
        cin >> t;
        d[i] = t;
        se[t]++;
    }
    
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            cnt[b[i]]++;
            if(se[b[i]] == 0){
                cout << "NO" << endl;
                return;
            }
            se[b[i]]--;
        }
    }
    
    if(ma[t])cout << "YES" << endl;
    else cout << "NO" << endl;
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
