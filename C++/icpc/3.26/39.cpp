#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<string,int>

const int mod = 1e9 + 7;
const int N = 1e4 + 10;
vector<pair<array<int, 100>, int>> a;
int n, m;
map<array<int, 100>, int> ma;
signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        array<int, 100> t;
        for(int j = 0; j < m; j++){
            cin >> t[j];
        }
        ma[t]++;
    }
    for(auto i : ma){
        a.push_back({i.first, i.second});
    }
    sort(a.begin(), a.end(), [&](pair<array<int, 100>, int> x, pair<array<int, 100>, int> y){
        if(x.second != y.second)
        return x.second > y.second;
        else{
            auto a=x.first;
            auto b=y.first;
            for(int i=0; i<m; i ++){
                if(a[i]!=b[i])
                return a[i]< b[i];
            }
        }
    });
    cout << a.size() << endl;
    for(auto[x,y]:a){
        cout << y << " ";
        for(int i=0 ;i<m ;i ++)
            cout<< x[i]<<" \n"[i ==m- 1];
    }
	return 0;
}
