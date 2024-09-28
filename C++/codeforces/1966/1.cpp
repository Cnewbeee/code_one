#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool cmp(int a, int b){
    return a > b;
}

void solve()
{
    int c[110] = {0};
    int n, k;
    cin >> n >> k;
    int r = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        c[t]++;
        if(c[t] == k) r = 1;
    }

    if(r){
        cout << k-1 << endl;
    }else{
        cout << n << endl;
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
