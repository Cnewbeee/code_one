#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];

signed main(void)
{
    double n;
    cin >> n;

    double l = -10000, r = 10000;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
	return 0;
}
