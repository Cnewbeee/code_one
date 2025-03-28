#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;

void solve()
{
    cin >> n;
    int c = 1, a, k = 1;
    set<int> s;
    cin >> a;
    s.insert(a);
    for(int i = 1; i < n; i++){
        int t;
        cin >> t;
        if(t == a)c++;
        s.insert(t);
    }
    if(n % 2 == 1){
        cout << "No" << endl;
        return;
    }
    if(c == n/2 && s.size() == 2)cout << "Yes" << endl;
    else cout << "No" << endl;
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
