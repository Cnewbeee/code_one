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
    int k, q;
    cin >> k >> q;
    //map<int, int> m;
    int a[k];
    for(int i = 0; i < k; i++){
        cin >> a[i];
        //m[a[i]] ++;
    }
    sort(a, a+k);
    for(int i = 0; i < q; i++){
        int ans = 0;
        cin >> ans;
        if(ans >= a[0])cout << a[0]-1 << " ";
        else cout << ans << " ";
    }
    cout << endl;
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
