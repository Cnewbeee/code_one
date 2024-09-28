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
    int sum = 0;
    string s;
    cin >> s;
    int p = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            sum ++;
            if(p == -1){
                p = i;
            }
        }
    }
    if(sum == 2){
        if(s[p+1] == '1')cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    else if(sum % 2 == 0){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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
