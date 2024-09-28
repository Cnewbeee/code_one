#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, k;
int a[N], b[N];
vector<PII> d;

bool cmp(PII a, PII b){
    return a.first > b.first;
}

void solve()
{
    int s = 0;
    cin >> n >> k;
    d.clear();
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        
        if(b[i] > a[i]){
            s += a[i];
            d.push_back({b[i], i});
        }
    }
    sort(d.begin(), d.end(), cmp);
    int l = 0;
    //for(int i = 0; i < d.size(); i++){cout << d[i].first << " ";}cout << endl;

    for(int i = k; i < d.size(); i++){
        l += b[d[i].second];
        //cout << b[d[i].second] << " ";
    }//cout << endl;
    if(l - s > 0)cout << l - s << endl;
    else cout << 0 << endl;
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
