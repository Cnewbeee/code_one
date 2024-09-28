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
    int n, hpa, hpb;
    cin >> n >> hpa >> hpb;
    int a[n], b[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];
    vector<int> aa, bb;
    for(int i = 0; i < n; i++){
        if(b[i] >= 0){
            bb.push_back(b[i]);
        }
    }
    int r = 0;
    int hpaa = hpa, hpbb = hpb;
    sort(a, a+n, greater<>());
    sort(bb.begin(), bb.end());
    for(int i = 0; i < bb.size(); i++){
        if(a[i] < 0)continue;
        hpaa -= bb[i];
        hpbb -= a[i];
        if(hpaa <= 0 || hpbb <= 0)break;
    }
    if(hpaa > 0 && hpbb <= 0)r = 1;

    if(r) cout << "yes" << endl;
    else cout << "no" << endl;
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
