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
    int r = 0;
    if(s[0] == '1' && s[1] >= '2'){
        r = 1;
        if(s[1] > '2')s[0] = '0', s[1] -= 2;
    }
    else if(s[0] == '2'){
        r = 1;
        if(s[1] >= '2'){
            s[0] -= 1, s[1] -= 2;
        }
        else{
            s[0] = '0', s[1] += 8;
        }
    }
    if(s[0] == '0' && s[1] == '0'){
        s[0] = '1', s[1] = '2';
    }
    if(r == 1)s += " PM";
    else s += " AM";
    cout << s << endl;
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
