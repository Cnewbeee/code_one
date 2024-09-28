#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n;

void solve()
{
    cin >> n;
    vector<int> a;
    map<int, int> ma;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
        if(ma[t] == 0)cnt++;
        ma[t]++;
    }
    sort(a.begin(), a.end());
    if(cnt % 2 == 1){
        cout << "Alice" << endl;
    }else if(a[0] > 1){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
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
