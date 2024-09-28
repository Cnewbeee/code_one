#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>
int ans[N], m[N], b[N];

const int mod = 1e9 + 7;
const int N = 2e5 + 10;

struct node{
	int v;
    int id;
}a[N];
bool cmp(const node& x, const node& y) {
	return x.v < y.v;
}
void solve()
{
    int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].v;
		a[i].id = i;
	}
	string s;
	cin >> s;
	int rs = 0, rb = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			m[++rs] = a[i + 1];
		}
		else {
			b[++rb] = a[i + 1];
		}
	}
    sort(m + 1, m + rs + 1, cmp);
	sort(b + 1, b + rb + 1, cmp);
	for (int i = 1; i <= rs; i++) {
    	ans[m[i].id] = i;
	}
	for (int i = 1; i <= rb; i++) {
		ans[b[i].id] = rs + i;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
    cin >> t;

    while (t -- ){
        solve();
    }

	return 0;
}
