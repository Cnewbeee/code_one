#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int m, n;
    cin >> n >> m;
    //int a[n+1][m];
    map<int, vector<pair<int, int>>> ma;
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int t ;
            cin >> t;
            //cin >> a[i][j];
            ma[t].push_back({i, j});
        }
    for(auto [f, s] : ma){
        int len = s.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                sum += abs(s[i].first - s[j].first) + abs(s[i].second - s[j].second);
            }
        }
    }
    cout << sum << endl;
    return 0;
}