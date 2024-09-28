#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
vector<int> a, b;

void solve()
{
    int n, m;
    cin >> n;
    ll suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
        suma += t;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        b.push_back(t);
        sumb += t;
    }
    if(suma != sumb){
        cout << -1 << endl;
        return ;
    }
    int i = 0, j = 0;
    int x = 0, y = 0, len = 0;
    while(i < n && j < m){
        while(x == y && i < n && j < m){
            x += a[i++];
            y += b[j++];
            len++;
        }
        while(x != y && i < n && j < m){
            if(x > y){
                y += b[j++];
            }
            else if(x < y){
                x += a[i++];
            }
        }
        //len++;
        x = 0, y = 0;
    }
    cout << len << endl;
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
