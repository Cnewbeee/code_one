#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1010;
int n, m, q;
int g[N][N], s[N][N];

signed main(void)
{
	cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] + g[i][j] - s[i-1][j-1];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << endl;
    }

	return 0;
}
