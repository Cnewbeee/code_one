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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n-1;

    while(l <= r){
        int d = 0;
        int m = min(a[l], a[r]);
        if(l == r)d = a[l];
        else d = 2 * m;

        if(k >= d){
            k -= d;
        }else{
            int res = n - (r-l+1);
            if(k == 2 * m - 1 && a[l] == m)res++;
            cout << res << endl;
            return;
        }
        if(a[l] < a[r]){
            a[r] -= m;
            l++;
        }else if(a[l] > a[r]){
            a[l] -= m;
            r--;
        }else{
            r--, l++;
        }
    }
    cout << n << endl;
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
