#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int, int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int x;
    cin >> x;
    int a[32] = {0};
    int n;
    for(int i = 0; i <= 31; i++){
        if(x & (1 << i))a[i] = 1, n = i;
    }
    
    for(int i = 0, j = 1; j < 32; i++, j++){
        if(a[i] == 1 && a[j] == 1){
            while(a[i] == 1 && a[j] == 1){a[j] = 0,j++;}
            a[i] = -1, a[j] = 1;
            n = max(n, j);
            i = j-1;
        }
    }
    cout << n+1 << endl;
    for(int i = 0; i <= n; i++){
        cout << a[i] << " ";
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
