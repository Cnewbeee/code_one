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
    int a[n], b[n];
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        b[i-1] = gcd(a[i-1], a[i]);
    }
    int r = 1;
    for(int i = 0; i < n-1; i ++){
        if(b[i] > b[i+1] && r){
            r--;
            int k = 0;
            if(i > 1){
                int t = gcd(a[i], a[i-1]);
                if(t >= b[i-2] && t <= b[i]){
                    continue;
                }
                t = gcd(a[i+1], a[i]);
                if(t >= b[i] && t <= b[i+1]){
                    b[i] = t;
                    continue;
                }
                cout << "NO" << endl;
                return ;
            }
            else{
                int t = gcd(a[i+1], a[i]);
                if(t >= b[i] && t <= b[i+1]){
                    b[i] = t;
                    continue;
                }
                cout << "NO" << endl;
                return ;
            }
        }else if(b[i-1] > b[i]){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    return ;
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
