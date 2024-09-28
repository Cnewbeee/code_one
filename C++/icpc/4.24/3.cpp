#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
vector<int> a;
map<int, int> ma;
void solve()
{
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
        ma[t]++;
    }
    if(ma.size() == n && n % 2 == 1){
        cout << "NO" << endl;
    }

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
