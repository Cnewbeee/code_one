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
    int b[2] = {0};
    b[1] = n+2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        if(b[0] != 0 && a[k] < a[i]){
            b[1] = i;
            break;
        }
        if(b[0] == 0 && a[k] < a[i]){
            b[0] = i;
        }
    }
    int ma1 = 0, ma2 = 0;
    if(b[0] == 0){
        cout << n-1 << endl;
        return ;
    }
    ma1 = b[0]-2;
    ma2 = min(k, b[1]) - b[0];
    if(b[0] == 1)ma2--;
    cout << max(ma1, ma2) << endl;

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
