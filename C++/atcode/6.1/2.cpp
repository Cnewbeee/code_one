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
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    int c[m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int t;
            cin >> t;
            c[j] += t;
        }
    }
    for(int i = 0; i < m; i++){
        if(c[i] < a[i]){
            cout << "No" << endl;
            return ;
        }
    }
    //cout << c[3] << endl;
    cout << "Yes" << endl;
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
