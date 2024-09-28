#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int n, x, y;
void solve()
{
    cin >> n >> x >> y;

    for(int i = 0; i < x; i++)cin >> a[i];

    sort(a, a+x);
    int sum = x - 2;

    for(int i = 0; i < x-1; i++){
        if(a[i+1] - a[i] == 2)sum++;
    }
    if(a[x-1] - a[0] - n == 0)sum ++;

    cout << sum << endl;
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
