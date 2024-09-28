#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 10;
vector<string> s(N);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        a[i] = i;
    }
    do{
        int rr = 1;
        for(int i = 0; i < n-1; i++){
            string x = s[a[i]], y = s[a[i+1]];
            int c = 0;
            for(int j = 0; j < m; j++){
                if(x[j] != y[j]){
                    c++;
                }
            }
            if(c > 1){
                rr = 0;
                break;
            }
        }
        if(rr){
            cout << "Yes" << endl;
            return ;
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << "No" << endl;
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
