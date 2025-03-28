    #include <bits/stdc++.h>
    #define endl '\n'
    #define ll long long
    using namespace std;

    //#define int long long
    #define PII pair<int,int>

    const int mod = 1e9 + 7;
    const int N = 1e6 + 10;

    int lsp(string a, string b){
        int j = 0;
        while(j < a.length() && j < b.length() && b[j] == a[j]){++j;}
        return j;
    }

    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        int l ,r;
        //cin >> l >> r;

        sort(s.begin(), s.end());

        int mx = 0;

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += s[i].length() * 2;
            if(i)ans -= lsp(s[i], s[i - 1]) * 2;
            mx = max(mx, int(s[i].length()));
        }
        cout << ans - mx << endl;
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
