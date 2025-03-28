#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int ans = 0;

int val(string s){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        string t = s;
        int cnt1 = 0, cnt0 = 0;
        if(t[i] == '0')t[i] = '1';
        else t[i] = '0';
        for(int j = 0; j < t.length()-1; j++){
            if(t[j] == '1' && t[j+1] == '0'){
                cnt1++;
            }else if(t[j] == '0' && t[j+1] == '1'){
                cnt0++;
            }
        }
        if(cnt1 == cnt0)res++;
    }
    return res;
}

void getstr(string s, int u){
    if(u == s.length()){
        ans += val(s);
        return;
    }
    if(s[u] == '?'){
        s[u] = '0';
        getstr(s, u+1);
        s[u] = '1';
        getstr(s, u+1);
    }else{
        getstr(s, u+1);
    }
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ans = 0;
    
    getstr(s, 0);
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
