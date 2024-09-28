#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
bool cmp(PII a, PII b){
    return a.second < b.second;
}
void solve()
{
    
    int n;
    cin >> n;
    vector<PII> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> b[i];
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<>());
    //for(int i = 0; i < n; i++)cout << a[i].first << " " <<  a[i].second.first << endl;
    int ee = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i].second != n+1){
            for(int j = i+1; j < n; j++){
                if(b[a[i].second] < b[a[j].second] && a[j].second != n+1){
                    //cout << a[i].second.first << endl;
                    a[j].second = n+1, ee++;
                }
            }
        }
    }
    cout << n-ee << endl;
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n-ee; i++){
        if(a[i].second != -1){
            cout << a[i].second+1 << " ";
        }
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
