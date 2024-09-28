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
    string a;
    cin >> n >> a;
    int r = 0;
    if(a[0] >= '0' && a[0] <= '9'){
        r = 1;
    }
    for(int i = 1; i < n; i++){
        if(a[i] >= 'a' && a[i] <= 'z' && r){
            r = 0;
        }else if(a[i] >= '0' && a[i] <= '9' && !r){
            cout << "NO" << endl;
            return ;
        }else if(a[i] < a[i-1]){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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
