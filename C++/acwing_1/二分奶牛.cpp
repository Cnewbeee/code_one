#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, c, a;
int f[N];
bool check(int x){
    int l = f[0];
    int num = 0;
    for(int i = 1; i < n; i++){
        if(f[i] - l < x) num++;
        else l = f[i];
        if(num > a) return false;
    }
    return true;
}

signed main(void)
{
	cin >> n >> c;
    a = n-c;
    for(int i = 0 ; i < n; i++)
        cin >> f[i];

    sort(f, f+n);
    int l = 1;
    int r = f[n-1] - f[0];
    while(l+1 < r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r)) cout << r;
    else cout << l;
	return 0;
}
