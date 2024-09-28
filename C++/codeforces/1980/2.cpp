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
    int n, f, k;
    cin >> n >> f >> k;
    set<int> se;
    map<int, int> ma;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v[i] = t;
        se.insert(t);
        ma[t]++;
    }
    int num = v[f-1];
    int cnt = ma[num];
    int r = -1;
    //cout << num << " " << cnt << endl;
    sort(v.begin(), v.end(), greater<>());
    //for(int i = 0; i < n; i++)cout << v[i] << " ";cout << endl;
    for(int i = 0; i < n; i++){
        if(v[i] == num && i < k){
            r = 1;
        }else if(v[i] == num && i < k + cnt - 1 && r == 1 && i >= k){
            //cout << v[i] << " ";
            r = 0;
        }
    }
    if(r == 0)cout << "MAYBE" << endl;
    else if(r == 1)cout << "YES" << endl;
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
