#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 25;
int n, m, k;
queue<int> tui;
stack<int> he;
int a[N][1000];
int pa[N];
void solve(int cnt)
{
    int p = 1;
    while(1){
        int r = 1;
        while(a[cnt][p] >= tui.front()){
            a[cnt][++p] = tui.front();
            tui.pop();
            r = 0;
        }
        while(a[cnt][p] >= he.top()){
            a[cnt][++p] = he.top();
            he.pop();
            r = 0;
        }
        if(r == 1){
            pa[cnt] = p;
            return ;
        }
    }
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        tui.push(t);
    }

    for(int i = 1; i <= m; i++){
        solve(i);
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= pa[i]; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
