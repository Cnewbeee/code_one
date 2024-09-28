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
	int n;
    cin >> n;
    vector<set<int>> se(n);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        while(m--){
            int t;
            cin >> t;
            se[i].insert(t);
        }
    }

    int m; cin >> m;
    set<int> s;
    while(m--){
        s.clear();
        int a, b;
        cin >> a >> b;
        a--, b--;
        s = se[a];    
        for(int i : se[b]){
            s.insert(i);
        }
        double sum = double(se[a].size()+se[b].size()-s.size())/s.size()*100.0;
        printf("%.2lf\%\n", sum);
    }

	return 0;
}
