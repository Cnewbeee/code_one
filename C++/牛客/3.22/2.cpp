#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 5e5 + 10;
ll a[N];
ll f[N] = {0};

void solve()
{
    int n;
    cin >> n;
    
    ll sum = 0;
   
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        a[i] += sum;
        if(a[i] < 0){
            sum += a[i];
        }else if(i != n){
            a[n] += a[i];
        }
    }
    cout << a[n] << endl;
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
