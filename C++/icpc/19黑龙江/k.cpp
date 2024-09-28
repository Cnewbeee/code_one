#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
vector<int> n(4), t(4);
int st[4];
vector<vector<int>> nn(100);
int p = 0;
char cc[] = "+-*";
void dfs(int u){
    if(u == 4){
        nn[p++] = t;
        return ;
    }
    for(int i = 0; i < 4; i++){
        if(st[i])continue;
        t[u] = n[i];
        st[i]++;
        dfs(u+1);
        st[i] = 0;
    }
}

void solve()
{
    for(int i = 0; i < 4; i++){
        cin >> n[i];
    }
    set<int> se;
    dfs(0);
    
    for(int l = 0; l < p; l ++){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int a = nn[l][0], b = nn[l][1], c = nn[l][2], d = nn[l][3];
                    int ans = 0;
                    if(k == 2){
                        c *= d;
                        d = 1;
                    }
                    if(j == 2){
                        b *= c;
                        c = 1;
                    }
                    if(i == 0){
                        ans = a + b;
                    }else if(i == 1){
                        ans = a - b;
                    }else{
                        ans = a * b;
                    }
                    if(j == 0){
                        ans += c;
                    }else if(j == 1){
                        ans -= c;
                    }else{
                        ans *= c;
                    }
                    if(k == 0){
                        ans += d;
                    }else if(k == 1){
                        ans -= d;
                    }else{
                        ans *= d;
                    }
                    
                    se.insert(ans);
                    //cout << ans << " ";
                }
            }
        }
    }
    //cout << endl;
    cout << se.size() << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
