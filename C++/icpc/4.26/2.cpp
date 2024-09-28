#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
void solve()
{
    int n, m;
    cin >> n >> m;
    int an = ceil(sqrt(m * 2));
    
    if(m * 2 <= n){
        cout << n - m * 2 << " ";
    }else {
        cout << 0 << " ";
    }

    if(m == 1){
        cout << n - 2 << endl; 
        return ;
    }else if(m == 0){
        cout << n << endl;
        return ;
    }
    for(int i = 1; i < N; i++){
        int t = i * (i - 1) / 2;
        if(t >= m){
            cout << n - i << endl;
            return;
        }
    }
    
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
