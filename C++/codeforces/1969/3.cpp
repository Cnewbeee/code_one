#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 3e5 + 10;
bool cmp(int a, int b){
    return a > b;
}
int n, k;
int a[N], b[N];
map<int, stack<int>> ma;

void solve()
{
    ll sum = 0;
    int mi = 1e9;
    cin >> n >> k;
    ma.clear();
    cin >> a[0];
    mi = a[0];
    b[0] = 0;
    if(n == 1){
        cout << a[0] << endl;
        return ;
    }
    sum += a[0];
    for(int i = 1; i < n; i++){cin >> a[i]; b[i] = abs(a[i]-a[i-1]);ma[b[i]].push(i);sum += a[i];if(mi > a[i])mi = a[i];}
    if(k >= n-1){
        cout << mi * n << endl;
        return;
    }
    sort(b, b+n, cmp);
    //for(int i = 0; i < n; i++){cout << b[i] << " ";}cout << endl;
    for(int i = 0; i < min(k, n-1); i++){
        if(a[ma[b[i]].top()] >= a[ma[b[i]].top()-1]){
            sum -= a[ma[b[i]].top()] - a[ma[b[i]].top()-1];
            a[ma[b[i]].top()] = a[ma[b[i]].top()-1];
        }
        else{
            sum -= a[ma[b[i]].top()-1] - a[ma[b[i]].top()];
            a[ma[b[i]].top()-1] = a[ma[b[i]].top()];
        }
        //cout << sum << endl;
    }
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
