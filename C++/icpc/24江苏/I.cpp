#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int n;
int a[N], b[N];
void solve()
{
    cin >> n;
    vector<int> f1, f0, s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    auto check = [&](int x){
        multiset<int> p1, p0;
        int r = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == 1){
                if(!p0.size()){
                    p1.insert(a[i]);
                }else{
                    auto p = p0.lower_bound(x-a[i]);
                    if(p == p0.end()){
                        return 0;
                    }
                    p0.erase(p);
                    r = 1;
                }
            }else{
                if(!p1.size()){
                    p0.insert(a[i]);
                }else{
                    auto p = p1.lower_bound(x-a[i]);
                    if(p == p1.end()){
                        return 0;
                    }
                    p1.erase(p);
                    r = 1;
                }
            }
        }
        return r;
    };

    int l = 0, r = 2e8;

    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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
