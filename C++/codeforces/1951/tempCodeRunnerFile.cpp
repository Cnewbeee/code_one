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
    int n, k;
    cin >> n >> k;
    int a[n+1];
    int kk, m = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == k){
            kk = a[i];
        }
        if(a[i] > a[m]){
            m = i;
        }
    }
    int e = -1;
    for(int i = 1; i <= n; i++){
        if(a[i] >= a[k]){
            e = i;
            break;
        }
    }
    if(e == 1 || e == 2){
        cout << 0 << endl;
    }
    else if(e != k){
        if(k-e > e-2)cout << k-e << endl;
        else cout << e-2 << endl;
    }
    else {
        cout << n - k + 1 << endl;
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
