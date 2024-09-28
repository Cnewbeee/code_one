#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool st[N] = {0};
    int idx = 0;
    for(int i = 0; i < n; i++){
        while(st[idx]){
            idx++;
        }

        if(a[i] > 0){
            cout << idx << " ";
            st[idx] = true;
        }
        else {
            cout << idx - a[i] << " ";
            st[idx-a[i]] = true;
        }
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
