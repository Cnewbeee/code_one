#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, a, b;
int ans[N], num[N], cnt = mod, an[N];
int sum = 0;

void dfs(int u, int sub, int i){
    //cout << u << " " << sub << " " << i << endl;
    if(u >= cnt)return;
    if(i == n-1){
        if(cnt > u && sub <= 0){
            cnt = u;
            for(int i = 0; i < u; i++){
                ans[i] = an[i];
            }
        }
        return;
    }

    int sub1 = 0, sub2 = 0, sub3 = 0, cn = 0;
    dfs(u+cn, sub, i+1);
    int mx = max(num[i-1]/b, max(num[i]/a, num[i+1]/b))+1;
    while(cn < mx){
        an[u+cn] = i+1;
        cn++;
        if(num[i-1] >= b)num[i-1] -= b, sub -= b,sub1 += b;
        else sub -= num[i-1], sub1 += num[i-1], num[i-1] = 0;
        if(num[i] >= a)num[i] -= a, sub -= a, sub2 += a;
        else sub -= num[i], sub2 += num[i], num[i] = 0;
        if(num[i+1] >= b)num[i+1] -= b, sub -= b, sub3 += b;
        else sub -= num[i+1], sub3 += num[i+1], num[i+1] = 0;
        if(num[i-1] == 0)dfs(u+cn, sub, i+1);
       
    } 
    num[i-1] += sub1;
    num[i] += sub2;
    num[i+1] += sub3;
    sub += sub1 + sub2 + sub3;
}

void solve()
{
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        num[i]++;
        sum += num[i];
    }
    dfs(0, sum, 1);

    cout << cnt << endl;
    for(int i = 0; i < cnt; i ++){
        cout << ans[i] << ' ';
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
