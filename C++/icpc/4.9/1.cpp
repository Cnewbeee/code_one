#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int Stoi(char t){
    ll num = 0;
    if(t >= '0' && t <= '9'){
        num = (t-'0');
    }
    else if(t >= 'A' && t <= 'Z'){
        num = (t-'A'+10);
    }
    return num;
}
char Itoc(int x){
    char res;
    if(x <= 9)res = x + '0';
    else res = x - 10 + 'A';
    return res;
}

void solve(){
    string ans; 
    int x;
    ll s;
    cin >> s >> x;
    while(s > 0) {
        int t = s % x;
        s /= x;
        ans.push_back(Itoc(t));
    }
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;
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
