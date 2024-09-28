#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
vector<int> ans;
ll anss;
void div(vector<int> a, ll b, ll &r){
    vector<int> c;

    r = 0;
    for(int i = 0; i < a.size(); i++){
        r = r * 10 + a[i];
        c.push_back(r/b);
        r %= b;
    }
    //cout << r << endl;
}
bool sm(vector<int> a){
    for(int i = 0; i < n; i++){
        if(a[i] < ans[i])return true;
        else if(a[i] > ans[i])return false;
    }
    return false;
}
void gjd(vector<int> a, vector<int> b){
    vector<int> res(2*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i+j+1] += (a[i])*(b[j]);
        }
    }
    for(int i = 2*n-1; i > 0; i--){
        if(res[i]>=10){
            res[i-1] += res[i]/10;
            res[i] = res[i]%10;
        }
    }
    div(res, 998244353, anss);
}
void solve()
{
    
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        x[i] = a[i]-'0';
        y[i] = b[i]-'0';
        if(y[i] > x[i])swap(x[i], y[i]);
    }
    ll aa, bb;
    div(x, 998244353, aa);
    div(y, 998244353, bb);
    //for(int ii : x)cout << ii;cout << endl;
    //for(int ii : y)cout << ii;cout << endl;
    //gjd(x, y);
    //cout << anss << endl;
    cout << aa * bb % 998244353 << endl;
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
