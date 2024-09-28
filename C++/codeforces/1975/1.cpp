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
    int l, t;
    int a;
    int cnt = 0;
    cin >> a;
    l = a;
    for(int i = 0; i < n-1; i++){
        cin >> t;
        if(l <= t){
            l = t;
        }else{
            cnt++;
            //cout << t << endl;
            l = t;
        }
    }
    if(cnt == 0){
        cout << "Yes" << endl;
    }else if(cnt == 1 && a >= t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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
