#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 5e5 + 10;
int lowbit(int x){
    return x & -x;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    
	    int res = 0;
	    while(x){
	        res ++;
	        x -= lowbit(x);
	    }
	    cout << res << " ";
	}

	return 0;
}
