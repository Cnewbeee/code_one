#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool check(int m){
    while(m > 0){
        int s = m % 10;
        if(s % 7 == 0 && s != 0){
            return true;
        }
        m /= 10;
    }
    return false;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    m++;
    while(k--){
        //cout << m;
        if(m % 7 == 0 && m != 0){
            cout << 'p' << " ";
        }else if(check(m)){
            cout << 'p' << " ";
        }else{
            cout << m << " ";
        }
        m += 2;
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
