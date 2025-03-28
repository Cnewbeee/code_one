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
    string s, p = "CHICKEN";
    cin >> n >> s;
    int ans = 0;
    if(n < 7 || n % 2 == 0){
        cout << "NO" << endl;
        return;
    }

    int cnt[26] = {0};
    int j = 0;
    int sum = 0, ma = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == p[j]){j++;}
        else{cnt[s[i] - 'A']++;}
    }

    if(j != 7){
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < 26; i++){
        sum += cnt[i];
        if(cnt[i] > ma){ma = cnt[i];}
    }

    if(sum / 2 >= ma){
        cout << "YES" << endl;
    }else{
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
