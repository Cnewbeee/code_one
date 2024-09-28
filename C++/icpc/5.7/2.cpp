#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
map<string, int> ma;
string t;
int st[5];
string na = "Timur";
void dfs(int u){
    if(u == 6){
        //cout << t << endl;
        ma[t]++;
        return ;
    }
    for(int i = 0; i < 5; i++){
        if(st[i])continue;
        t.push_back(na[i]);
        st[i] = 1;
        dfs(u+1);
        st[i] = 0;
        t.erase(t.size()-1);
    }
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if(n != 5){
        cout << "NO" << endl;
        return ;
    }
    if(ma[s]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;
    dfs(1);

    while (T -- ){
        solve();
    }

	return 0;
}
