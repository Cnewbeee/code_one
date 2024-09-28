#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, m;
int w[N], d[N], s[N], t[N];
ll cha[N];

bool check(int mid)
{
    memset(cha, 0, sizeof cha);
    for(int i = 1 ; i <= mid; i++){
        cha[s[i]] += d[i];
        cha[t[i]+1] -= d[i];
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += cha[i];
        if(sum > w[i])
            return false;
    }
    return true;
    
}

signed main(void)
{
    cin >> n >> m;
    
	for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];

    int l = 0, r = m;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if(r == m)
        cout << 0 << endl;
    else
        cout << -1 << endl << r + 1 << endl;

	return 0;
}
