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
    if(n == 1){
        printf("%d\n", k);
        return ;
    }
    k++;
    int c = log(k) / log(2);
    //cout << c << endl;
    long long an = powf(2, c) - 1;
    printf("%lld", an);
    k--;
    k -= an;
    printf(" %d", k);
    for(int i = 2; i < n; i++){
        printf(" 0");
    }
    printf("\n");
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
