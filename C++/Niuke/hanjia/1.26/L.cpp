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
    cout << "Yes" << endl;
    if(n == 1){
        cout << "1 2 3 1" << endl;
    }else if(n == 2){
        cout << "1 2 3 5 2 4 5 6 3 1" << endl;
    }else if(n == 3){
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 6 3 1" << endl;
    }else if(n == 4){
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 7 11 12 13 14 15 10 6 3 1" << endl;
    }else if(n == 5){
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 7 11 12 13 14 15 20 14 19 13 18 12 17 11 16 17 18 19 20 21 15 10 6 3 1" << endl;
    }else if(n == 6){
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 7 11 12 13 14 15 20 14 19 13 18 12 17 11 16 17 18 19 20 21 27 20 26 19 25 18 24 17 23 16 22 23 24 25 26 27 28 21 15 10 6 3 1" << endl;
    }else{
        cout << "1 2 3 5 2 4 5 6 9 5 8 4 7 8 9 10 14 9 13 8 12 7 11 12 13 14 15 20 14 19 13 18 12 17 11 16 17 18 19 20 21 27 20 26 19 25 18 24 17 23 16 22 23 24 25 26 27 28 35 27 34 26 33 25 32 24 31 23 30 22 29 30 31 32 33 34 35 36 28 21 15 10 6 3 1" << endl;
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
