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
    string s;
    cin >> n >> s;
    int len = n * 4 - 1;
    string h[5];
    for(int j = 0; j < n; j++){
        if(s[j] == '0'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "X.X";if(j != n-1)h[1] += '.';
            h[2] += "X.X";if(j != n-1)h[2] += '.';
            h[3] += "X.X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '1'){
            h[0] += "..X";if(j != n-1)h[0] += '.';
            h[1] += "..X";if(j != n-1)h[1] += '.';
            h[2] += "..X";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "..X";if(j != n-1)h[4] += '.';
        }else if(s[j] == '2'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "..X";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "X..";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '3'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "..X";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '4'){
            h[0] += "X.X";if(j != n-1)h[0] += '.';
            h[1] += "X.X";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "..X";if(j != n-1)h[4] += '.';
        }else if(s[j] == '5'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "X..";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '6'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "X..";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "X.X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '7'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "..X";if(j != n-1)h[1] += '.';
            h[2] += "..X";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "..X";if(j != n-1)h[4] += '.';
        }else if(s[j] == '8'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "X.X";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "X.X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }else if(s[j] == '9'){
            h[0] += "XXX";if(j != n-1)h[0] += '.';
            h[1] += "X.X";if(j != n-1)h[1] += '.';
            h[2] += "XXX";if(j != n-1)h[2] += '.';
            h[3] += "..X";if(j != n-1)h[3] += '.';
            h[4] += "XXX";if(j != n-1)h[4] += '.';
        }
    }
    for(int i = 0; i < 5; i++){
        cout << h[i] << endl;
    }
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
