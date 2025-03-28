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
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());

    auto get_mid = [&](vector<int> &v){
        return (v[(v.size()-1)/2]);
    };

    auto get_sum = [&](vector<int> &v, int t){
        int sum = 0;
        for(int x : v) sum += abs(x-t);
        return sum;
    };

    int ans = 1e9, m1 = get_mid(b), m2 = get_mid(c);
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(m1+i < m2+j){
                ans = min(ans, get_sum(b, m1+i) + get_sum(c, m2+j));
            }
        }
    }
    cout << ans << endl;
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
