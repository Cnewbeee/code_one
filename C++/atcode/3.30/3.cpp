#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, a, b, c;
int an[N];

void solve()
{
    cin >> n >> a >> b;
    c = a + b;
    for(int i = 0; i < n; i++){
        cin >> an[i];
        an[i] %= c;
    }
    /*for(int i = 0; i < n; i ++){
        cout << an[i] << " ";
    }*/
    sort(an, an+n);
    
    //cout << endl;
    int ans = an[n-1] - an[0] -1 ;
    for(int i = 0; i < n; i++){
        ans = min(ans, a + b - (an[i + 1] - an[i] - 1));
    }
    if(ans > a) cout << "No" << endl;
    else cout << "Yes" << endl;
}
//5 2 7
//3232 65 5654 981 2233
//1    2  4    8   1

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
