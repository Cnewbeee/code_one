#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int, int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int x;
    cin >> x;
    string a, b;
    int n = -1;
    int y = 0;
    for(int i = x, j = 0; ;i++, j++){
        bitset<32> s1 = i, s2 = j;
        int l = 0, r = 1;
        for(int k = 0; k <= 31; k++){
            int lk = int(s1[k]) - int(s2[k]);
            if(l && lk){r = 0; break;}
            l = lk;
            if(lk)n = k;
        }
        if(r){
            a = s1.to_string();
            b = s2.to_string();
            break;
        }
    }
    cout << n+1 << endl;
    //cout << a << endl << b << endl;
    for(int i = 31; i >= 31-n; i--){
        int t;
        if(a[i] == '1' && b[i] == '1')t = 0;
        else if(a[i] == '1')t = 1;
        else if(b[i] == '1')t = -1;
        else t = 0;
        cout << t << " ";
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
