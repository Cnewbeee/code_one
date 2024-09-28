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
    int a[2*n+1];
    int b[n+1] = {0}, o = 0;
    int c[n+1] = {0}, p = 0;
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
        if(i <= n){
            b[a[i]]++;
            //o = b[a[i]] > o ? a[i] : o;
        }
        else{
            c[a[i]]++;
            //p = c[a[i]] > p ? a[i] : p;
        }
    }
    int cot = 2, sub = 0;
    for(int i = 1; i <= n; i++){
        if(b[i] == 2)o == i;
        if(cot == 2 && b[i] == 1)sub = i;
        if(cot == 1 && b[i] == 1){
            cout << sub << " " << i << " ";
            sub = abs(sub - i);
        }
    }
    for(int i = 1; i <= 2*k; i++){
        cout << i << " " ;
    }
    cout << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
    cin >> t;

    while (t--){
        solve();
    }

	return 0;
}
