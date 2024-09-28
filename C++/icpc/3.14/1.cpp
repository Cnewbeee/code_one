#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
char g[N];
void dfs(int u){
    if(u == n) {
        puts(g);
        return;
    }
    g[u] = 'N';
    dfs(u+1);
    g[u] = 'Y';
    dfs(u+1);
}

signed main(void)
{
    cin >> n;

    dfs(0);

	return 0;
}
