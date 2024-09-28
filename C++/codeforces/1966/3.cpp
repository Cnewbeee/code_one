#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
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
    a.erase(unique(a.begin(), a.end()), a.end());
    int c = a[0];
    if(c != 1 || cnt == 1){
        cout << "Alice" << endl;
        return ;
    }
    bool ans = cnt % 2;
    vector<int> d;
    for(int i = 1; i < cnt-1; i++){
        if(a[i] != a[i-1]+1){
            if(i % 2 == 0){
                cout << "Alice" << endl;
            }else{
                cout << "Bob" << endl;
            }
            return ;
        }
    }
    if(cnt % 2 == 1)cout << "Alice" << endl;
    else cout << "Bob" << endl;
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
