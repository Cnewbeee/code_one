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
    int n, c, d;
    cin >> n >> c >> d;

    map<int, int> a;
    int r = 0;
    int f = 1e9;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[x]++;
            if(f > x)f = x;
        }
    }
    int b[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == 0 && j == 0)b[i][j] = f;
            else if(j != 0){
                b[i][j] = b[i][j-1] + d;
            }
            else if(i != 0 && j == 0){
                b[i][j] = b[i-1][j] + c;
            }
            if(a.count(b[i][j]) == 0){
                r = 1;
                break;
            }else{
                a[b[i][j]] --;
            }
        }
    }
    for(auto it : a){
        if(it.second != 0){
            r = 1;
            break;
        }
    }
    if(r == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
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
