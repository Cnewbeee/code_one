#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 5e5 + 10;
int a[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    int p = 1;
    set<int> se;
    vector<int> ans;

    while(q--){
        int op, t;
        cin >> op;
        if(op == 2){
            cin >> t;
            se.erase(t);
        }else if(op == 1){
            se.insert(p++);
        }else{
            int tt;
            for(int i : se){
                tt = i;
                break;
            }
            ans.push_back(tt);
        }
    }
    //sort(ans.begin(), ans.end());
    for(int i : ans)cout << i << endl;
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
