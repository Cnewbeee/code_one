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
    int n, h, m;
    cin >> n >> h >> m;
    map<string, int> a, b, c;
    int x = 0, y = 0, z = 0;
    for(int i = 1; i <= n; i++){
        string id; 
        int ye, mon, d, ho, mi, se;
        char sep;
        cin >> id >> ye >> sep >> mon >> sep >> d >> ho >> sep >> mi >> sep >> se;
        if(ye == h && mon == m){
            if(ho >= 11 && (ho < 13 || (ho == 13 && mi == 0 && se == 0))){
                if(b[id] == 0)y++, b[id] = 1;
            // cout << "b" << " " << ye << " " << mon << " " << d << " " << ho << " " << mi << " " << se << endl;
            }else if((ho >= 7 && (ho < 9 || (ho == 9 && mi == 0 && se == 0)))||(ho >= 18 && (ho < 20 || (ho == 20 && mi == 0 && se == 0)))){
                if(a[id] == 0)x++, a[id] = 1;
            // cout << "a" << " " << ye << " " << mon << " " << d << " " << ho << " " << mi << " " << se << endl;
            }else if(ho >= 22 ||(ho >= 0 && (ho < 1 || (ho == 1 && mi == 0 && se == 0)))){
                if(c[id] == 0)z++, c[id] = 1;
            // cout << "c" << " " << ye << " " << mon << " " << d << " " << ho << " " << mi << " " << se << endl;
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    // cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
