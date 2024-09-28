#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 5e6 + 10;
int a[N];
int d[N];
int n, m;
signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y+1] -= z;
    }
    int mi = 101;
    for(int i = 1; i <= n; i++){
        d[i] += d[i-1];
        a[i] += d[i];
        mi = min(mi, a[i]);
    }
    cout << mi << endl;

	return 0;
}
