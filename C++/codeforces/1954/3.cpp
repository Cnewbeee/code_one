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
    string a, b;
    cin >> a >> b;
    int r = 0;
    for(int i = 0; i <= a.size(); i++){
        if(r == 0){
            if(a[i] > b[i])r = 1;
            else if(a[i] < b[i]) r = -1;
        }
        else if(r == 1){
            if(a[i] > b[i]) swap(a[i], b[i]);
        }
        else if(r == -1){
            if(a[i] < b[i]) swap(a[i], b[i]);
        }
    }
    cout << a << endl << b << endl;
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
