#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool cmp(int a, int b){
    if(a ^ b < 4)return a < b;
    else return true;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    map<int, priority_queue<int, vector<int>, greater<int>>> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        m[a[i]>>2].push(a[i]);
    }

    for(int i = 0; i < n; i++){
        cout << m[a[i]>>2].top() << " ";
        m[a[i]>>2].pop();
    }
    cout << endl;
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
