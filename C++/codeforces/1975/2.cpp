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
    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    sort(v.begin(), v.end());
    if(v[0] == 1){
        cout << "Yes" << endl;
        return ;
    }
    int k = v[0];
    int kk = -1;
    for(int i = 1; i < n; i++){
        if(v[i] % k != 0 && kk == -1){
            kk = v[i];
        }else if(v[i] % k != 0 && v[i] % kk != 0){
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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
