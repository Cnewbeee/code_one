#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    set<int> se;
    map<int, int> m;
    vector<int> a;
    int ma = 0;
    int en, be;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        se.insert(t);
        a.push_back(t);
        m[t] ++;
        if(m[ma] < m[t])ma = t;
    }
    
    if(se.size() == 1){
        cout << -1 << endl;
        return ;
    }
    int an = 1e9;
    for(int i = 1; i < n; i++){
        if(a[i] != a[0]){
            for(int j = i + 1; j < n; j++){
                if(a[j] != a[0]){
                    an = min(an, j - i - 1);
                    break;
                }
            }
        }
    }
    //cout << an << " << " << endl;
    int ans = 0;
    while(a[ans] == a[n-1]){
        ans++;
    }
    int pp = n-1;
    int anss = 0;
    while(a[pp] == a[0]){
        anss++;
        pp--;
    }
    ans = min(ans, anss);
    cout << min(ans, an) << endl;
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
