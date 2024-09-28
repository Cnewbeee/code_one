#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
string a = "wbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbwwbwbwwbwwbwwbwwbw";

void solve()
{
    int w, b;
    cin >> w >> b;
    
    for(int i = 0; i <= 12; i++){
        int W = 0, B = 0;
        for(int j = i; j < w+b+i; j++){
            if(a[j] == 'w')W++;
            else B++;
        }
        //cout << W << " ++ " << B << endl;
        if(W == w && b == B){
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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
