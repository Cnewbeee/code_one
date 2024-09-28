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
    string s;
    cin >> s;
    int n = s.size();

    int a[12] = {0};
    a[1] = 1;
    for(int i = 2; i <= 11; i++){
        a[i] = a[i-1] * i;
        //cout << a[i] << " ";
    }
    //cout << endl;
    int b[11] = {0};
    for(int i = n-1; i >= 1; i--){
        b[n-i] = a[i];
        //cout << a[i] << " " ;
    }
    //cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = i + 1; j < n; j++){
            if(s[i] > s[j]){
                c++;
            }
        }
        ans += c * b[i+1];
    }
    cout << ans << endl;
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
