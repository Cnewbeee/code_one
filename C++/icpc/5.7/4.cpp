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
    int g[3] = {0};
    string a[n], b[n], c[n];
    map<string, int> ma;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        ma[a[i]]++;
    }for(int i = 0; i < n; i++){
        cin >> b[i];
        ma[b[i]]++;
    }for(int i = 0; i < n; i++){
        cin >> c[i];
        ma[c[i]]++;
    }

    for(int i = 0; i < n; i++){
        string t[3];
        t[0] = a[i];
        t[1] = b[i];
        t[2] = c[i];
        for(int j = 0; j < 3; j++){
            if(ma[t[j]] == 1){
                //cout << i << endl;
                g[j] += 3;
            }else if(ma[t[j]] == 2){
                g[j] ++;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        cout << g[i] << " ";
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
