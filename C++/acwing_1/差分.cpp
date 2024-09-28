#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100010;
int a[N], b[N];
int n, m;
void insert(int l, int r, int c){
    b[l] += c;
    b[r+1] -= c;
}
signed main(void)
{
	cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        insert(i, i, a[i]);
    }

    while(m--){
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r , c);
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += b[i];
        cout << sum << " ";
    }
	return 0;
}
