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
    int n;
    cin >> n;
    int i;
    int p = 0;

    for(i = 0; i < 2*n; i++){
        for(int j = 0; j < n; j++){
            if((i + j + p) % 2 == 0)cout << "##";
            else cout << "..";
        }
        cout << endl;
        if(i % 2 == 0)p++;
    }
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
