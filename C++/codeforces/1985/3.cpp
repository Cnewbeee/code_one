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
    int n;
    cin >> n; 
    vector<int> a(n), b(n);
    set<int> s;
    int ans = 0;
    cin >> a[0];
    s.insert(a[0]);
    b[0] = a[0];
    if(a[0] == 0)ans++;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
        b[i] = b[i-1] + a[i];
        if(b[i] % 2 == 1){
            continue;
        }
        int t = b[i] / 2;
             if(s.count(t)){
            ans++;
        }
    }
    cout << ans << endl;
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
