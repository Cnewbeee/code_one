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
	int n;
    cin >> n;
    int a[n], b[n+1] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0)
            continue;
        b[i] = a[i-1] + b[i-1];
    }
    b[n] = b[n-1] + a[n-1];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l-1] << endl;
    }
	return 0;
}
