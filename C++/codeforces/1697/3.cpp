#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int a[3] = {0};
    int b[3] = {0};

    int n;
    cin >> n;
    string s, t;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        a[c-'a']++;
        s.push_back(c);
    }
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        b[c-'a']++;
        t.push_back(c);
    }
    if(a[0] != b[0] || a[1] != b[1] || a[2] != b[2]){
        cout << "NO" << endl;
        return ;
    }
    /*
    vector<int> sa, ta, sc, tc;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a')sa.push_back(i);
        if(s[i] == 'c')sc.push_back(i);
        if(t[i] == 'a')ta.push_back(i);
        if(t[i] == 'c')tc.push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(sc[i] < tc[i]){
            cout << "NO" << endl;
            return ;
        }
    }
    for(int i = 0; i < n; i++){
        if(sa[i] > ta[i]){
            cout << "NO" << endl;
            return ;
        }
    }*/
    //cin >> s >> t;
    int sa = 0, tc = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') sa++;
        if(t[i] == 'a') tc = 0, sa--;
        if(s[i] == 'c') sa = 0, tc--;
        if(t[i] == 'c') tc++;
        if(tc < 0 || sa < 0){
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
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
