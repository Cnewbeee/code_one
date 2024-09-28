#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int T = 1;
int a[] = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 
            1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 
            11001, 11010, 11011, 11100, 11101, 11110, 11111};

void solve()
{
    int n;
    cin >> n;
    int c = 6;
    while(c--)for(int i = 29; i >= 0; i--){
        if(n % a[i] == 0)n /= a[i];
    }
    
    //cout << n << ":::::";
    while(n > 0){
        int s = n % 10;
        if(s != 0 && s != 1){
            cout << "NO" << endl;
            return ;
        }
        n /= 10;
    }
    cout << "YES" << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
	
    cin >> T;

    while (T -- ){
        solve();

    }

	return 0;
}
