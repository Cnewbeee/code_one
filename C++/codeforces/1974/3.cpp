#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, a[N];
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            map<PII, int> ma;
            for(int k = 0; k < n-2; k++){
                ans += ma[{a[k+i], a[k+j]}]++;
                //cout << a[k+i] << " " << a[k+j] << endl;
            }
        }
    }
    //cout << ans << " <<< \n";   
    map<tuple<int, int, int>, int> mt;
    for(int i = 0; i < n-2; i++){
        ans -= 3 * mt[{a[i], a[i+1], a[i+2]}]++;
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
