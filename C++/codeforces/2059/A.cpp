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
    set<int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    if(a.size() >= 3 || b.size() >= 3){
        cout << "YES" << endl;
    }else if(a.size() == 1 || b.size() == 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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
