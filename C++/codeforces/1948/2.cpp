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
    vector<int> v, vv;

    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    int p = v.back();
    bool flag = 0;
    for(int i = v.size()-2; i >= 0; i --){
        if(p >= v[i])p = v[i];
        else{
            int a1 = v[i]/10, a2 = v[i]%10;
            if(a1 > a2){
                flag = 1;
            }
            if(a2 > p){
                flag = 1;
            }
            p = a1;
        }
    }
    if(flag)cout << "NO" << endl;
    else cout << "YES" << endl;
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
