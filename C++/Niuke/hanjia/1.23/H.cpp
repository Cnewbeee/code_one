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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = b - a, y = d - c;
    if(x < y){
        cout << a << ' ' << c << endl;
        cout << a << ' ' << c + 1 << endl;
        cout << a + 1 << ' ' << d << endl;
    }else{
        cout << a << " " << d << "\n";
        cout << a + 1 << " " << d << "\n";
        cout << b << " " << d - 1 << "\n";
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
