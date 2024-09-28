#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[1010];
vector<int> v;
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof a);
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        a[t]++;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i : v){
        if(a[i] == 1){
            for(int j = i + 1; j <= n * m; j ++){
                if(a[j] == 0){
                    a[j] = 2;
                    //cout << i << " " << j << endl;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << m - ans << endl;
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
