#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, a, b, c;
int an[N];
bool jue(int x){
    int r = 1;
        for(int j = 0; j < n; j++){
            int y = (x + an[j]) % c;
            if(y >= a){
                r = 0; 
                break;
            }
        }
    return r;
}

void solve()
{
    cin >> n >> a >> b;
    c = a + b;
    for(int i = 0; i < n; i++){
        cin >> an[i];
        an[i] %= c;
    }
    sort(an, an+n);
    for(int i = 0; i < c; i++){
        if(an[n-1]+i <= a){
            cout << "Yes" << endl;
            return ;
        }
    }
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
