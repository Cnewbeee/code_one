#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int n;
int a[N];

int getpri(int c){
    int m = c+1;
    
    while(1){
        int r = 0;
        for(int i = 0; i < n; i++){
            if(m % a[i] == 0){
                r = 1;
                break;
            }
        }
        if(r)m++;
        else break;
    }
    return m;
}

void solve()
{
    cin >> n;
    int r = 0, ma = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            r = 1;
        }
        if(a[i] > ma)ma = a[i];
    }
    if(r){
        cout << -1 << endl;
        return;
    }
    
    int ans = getpri(ma);

    cout << ans << endl;
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

