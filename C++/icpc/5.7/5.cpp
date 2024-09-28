#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n;
int a[N];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    ll sum = 0;
    queue<int> bt;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'R')a[i] = n-i;
        else a[i] = i-1;
        //cout << a[i] << " ";
        sum += a[i];
    }
    //cout << endl;
    for(int i = 1; i <= n/2; i++){
        if(s[i] == 'L')bt.push(i);
        if(s[n-i+1] == 'R')bt.push(n-i+1);
    }

    for(int i = 1; i <= n; i++){
        if(!bt.empty()){
            int t = bt.front();bt.pop();
            sum -= a[t];
            a[t] = max(t-1, n-t);
            sum += a[t];
            //cout << t << " << " << endl;
        }
        cout << sum << " ";
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
