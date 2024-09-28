#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    set<int> se;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int t;
            cin >> t;
            v[i].push_back(t);
            se.insert(t);
            //cout << t << " ";
        }
        //cout << endl;
        sort(v[i].begin(), v[i].end());
    }

    vector<int> pre, t;

    function<void(int u)> dfs = [&](int u){
        //cout << u << endl;
        if(pre.size() > t.size()){
            t = pre;
        }
        for(auto i : v[u]){
            pre.push_back(i);
            dfs(i);
            pre.pop_back();
        }
    };

    for(int i = 0; i < n; i++){
        if(!se.count(i)){
            pre.push_back(i);
            dfs(i);
        }
    }


    
    cout << t.size() << endl;
    for(int i = 0; i < t.size(); i++){
        cout << t[i] << " "[i == t.size()-1];
    }

	return 0;
}
