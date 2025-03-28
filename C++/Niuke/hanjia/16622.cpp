#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void print(int n){
    if(n == 0)return;
    
    if(n == 1)cout << 'x';
    else cout << "x^" << n;
}

void solve()
{
    int n;
    cin >> n;
    int a[n+1];
    
    for(int i = 0; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) continue;
        if(i == 0){
            if(n-i == 0){
                cout << a[i];
            }else if(a[0] == -1){
                cout << '-';
            }else if(a[0] == 1){
            }else{
                cout << a[i];
            }
        }else{
            if(a[i] > 0){
                cout << '+';
            }
            if(n-i == 0){
                cout << a[i];
            }else if(a[i] == -1){
                cout << '-';
            }else if(a[i] == 1){
            }else{
                
                cout << a[i];
            }
        }
        print(n-i);
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
