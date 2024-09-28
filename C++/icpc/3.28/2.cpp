#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
queue<int> q;
set<int> v;
int n, m;
int ans = 0;
signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> m >> n;

    while(n--){
        int t; cin >> t;
        if(!v.count(t)){
            if(v.size() >= m){
                v.erase(q.front());
                v.insert(t);
                q.pop();
                q.push(t);
            }
            else{
                v.insert(t);
                q.push(t);
            }
            ans++;
        }
    }
    cout << ans << endl;

	return 0;
}
