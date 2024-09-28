#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 110;

int g[N][N];
int f[N];
int n, m, k;
int Find(int x){
    if(f[x] != x)return f[x] = Find(f[x]);
    else return f[x];
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < N; i++)f[i] = i;

    while(m--){
        int a, b, p;
        cin >> a >> b >> p;
        g[a][b] = p;
        g[b][a] = p;

        if(p == 1){
            f[Find(a)] = Find(b);
        }
    }
    while(k--){
        int a, b;
        cin >> a >> b;
        if(Find(a) == Find(b) && g[a][b] == 1)cout << "No problem" << endl;
        else if(g[a][b] == -1 && Find(a) !=Find(b))cout << "No way" << endl;
        else if(g[a][b] == -1 && Find(a) == Find(b))cout << "OK but..." << endl;
        else cout << "OK" << endl;
    }

	return 0;
}
