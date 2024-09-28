#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int a[N], b[N];
int n, x;
bool cmp(int a, int b){
    return a > b;
}
void solve()
{
    cin >> n >> x;  
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = -1 * a[i];
    }
    if(x == 0){
        cout << "Yes" << endl;
        return ;
    }
    sort(a, a+n);
    sort(b, b+n, cmp);
    
    for(int i = 0, j = 0; i < n && j < n;){
        while(a[i] + b[j] < x && i < n)i++;
        while(a[i] + b[j] > x && j < n)j++;
        if(a[i] + b[j] == x){
            cout << "Yes" << endl;
            return ;
        }
        //cout << i << " :: " << j << endl;
    }
    cout << "No" << endl;
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
