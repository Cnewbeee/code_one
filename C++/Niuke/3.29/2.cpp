#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        int n;
    cin >> n;
    int a[n+1];
    int m1 = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m1 = max(m1, a[i]);
        sum += a[i];
    }
    
    if(n == 2 && a[2] == a[1]){
        cout << "0 0 "<< endl;
        continue;
    }
    //cout << m1 << " <<< " << endl;
    for(int i = 1; i <= n; i ++){
        if(a[i] == 1 && sum % 2 == 0)cout << "0 ";
        else if(a[i] == m1)cout << "1 ";
        else if(sum > m1 * 2) cout << "1 ";
        else cout << "0 ";
    }
    cout << endl;
    }

	return 0;
}
