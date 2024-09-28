#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
bool cmp1(pair<PII, int> a, pair<PII, int> b){
    return a.first.first > b.first.first;;
}bool cmp2(pair<PII, int> a, pair<PII, int> b){
    return a.first.second > b.first.second;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<pair<PII, int>> v, ca, cb;
    vector<PII> c;
    for(int i = 0; i < n + m + 1; i++){
        int a, b;
        cin >> a >> b;
        PII t = {a, b};
        v.push_back({t, i});
        c.push_back(t);
    }
    ca = v;
    cb = v;
    for(int j = 0; j < n+m+1; j++){
        ll sum = 0;
        int sum1 = 0, ln = n, lm = m;
        sort(v.begin(), v.end(), cmp1);
        for(int i = 0; i < ln; i++){
            if(v[i].second == j){ln++; continue;}
            sum1 += v[i].first.first;
            //cout << v[i].first.first << endl;
        }for(int i = ln; i < n+m; i++){
            if(v[i].second == j){lm++; continue;}
            sum1 += v[i].first.second;
            //cout << v[i].first.second << endl;
        }
        //cout << endl;
        int sum2 = 0;
        ln = n, lm = m;
        sort(v.begin(), v.end(), cmp2);
        for(int i = 0; i < lm; i++){
            if(v[i].second == j){lm++; continue;}
            sum2 += v[i].first.second;
            //cout << v[i].first.second << endl;
        }for(int i = lm; i < n+m; i++){
            if(v[i].second == j){ln++; continue;}
            sum2 += v[i].first.first;
            //cout << v[i].first.first << endl;
        }
        //cout << endl;
        sum = max(sum1, sum2);
        cout << sum1 << " " << sum2 << endl;
    }
    
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
