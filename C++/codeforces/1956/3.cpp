#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 500 + 10;
int d[N];
void print(int l, int r){
    for(int i = l; i <= r; i++){
        cout << i << " ";
    }
}
void solve()
{
    int n;
    cin >> n;
    int s = d[n], m;
    if(n == 1)m = 1;
    else m = n*2-1;
    cout << s << " " << m << endl;
    int r = n, l = n-1;
    if(n == 1)cout << "1 1 1 " << endl;
    else if(n == 2)cout << "1 1 1 2 " << endl << "1 2 1 2 " << endl << "2 1 1 2 " << endl;
    else if(n == 3)cout << "1 2 1 2 3 " << endl << "1 3 1 2 3 " << endl << "2 2 1 2 3 " << endl << "1 1 1 2 3 " << endl << "2 1 1 2 3 " << endl;
    else {
        for(int i = 0; i < m; i++){
            if(i % 2 == 0){
                cout << 1 << " " << r-- << " ";
                print(1, n);
                cout << endl;
            }else{
                cout << 2 << " " << l-- << " ";
                print(1, n);
                cout << endl;
            }
        }
    }
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    for(int i = 1; i < N; i++){
        d[i] = d[i-1] + (i*2-1) * i;
    }

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
