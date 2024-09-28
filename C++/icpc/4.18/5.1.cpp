#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 100 + 10;
vector<int> a(N);
void solve()
{
    int n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    int son = ceil((a[x] + a[y]) / 2);
    sort(a.begin() + 1, a.begin() + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] >= son){
            ans = i;
            break;
        }
    }
    if(abs(a[ans] - son) > abs(a[ans - 1] - son)) ans--;
    else if(abs(a[ans] - son) == abs(a[ans - 1] - son) && abs(a[ans] - son) == abs(a[ans - 1] - son));
    cout << ans << endl;
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
