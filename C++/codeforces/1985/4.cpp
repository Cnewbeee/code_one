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
    int n, m;
    cin >> n >> m;
    char ma[n][m];
    int x[n] = {0}, y[m] = {0};
    int x_max = -1, y_max = -1, anx = -1, any = -1;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char c;
            cin >> c;
            ma[i][j] = c;
            if(c == '#'){
                x[i]++;
                y[j]++;
            }
            if(y[j] > y_max){
                y_max = y[j];
                any = j;
            }
            if(x[i] > x_max){   
                x_max = x[i];
                anx = i;
            }
        }
    }
    anx++, any++;
    cout << anx << " " << any << endl;  
    // cout << ma[anx][any] << endl;
    // cout << x_max << " " << y_max << endl;
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
