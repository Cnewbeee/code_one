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
        int h, w;
        cin >> h >> w;
        char s[h][w+1];
        int a[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(a[i][j] == 0){
                    s[i][j] = '.';
                }else{
                    s[i][j] = a[i][j]+'A'-1;
                }
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << s[i][j];
            }
            cout << endl;
        }
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
