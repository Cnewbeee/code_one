#include<bits/stdc++.h>

using namespace std;

int n;
map<int, double> ma;
int cnt[10010];

bool cmp(pair<int, double> a, pair<int, double> b){
    if(a.second > b.second)return true;
    else if(a.second < b.second)return false;
    else if(cnt[a.first] > cnt[b.first])return true;
    else if(cnt[a.first] < cnt[b.first])return false;
    else if(a.first < b.first)return true;
    else return false;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        double sum = 0.0;
        while(k--){
            int a;
            double s;
            cin >> a >> s;
            ma[a] += s;
            sum += s;
            cnt[a]++;
        }
        ma[i] -= sum;
    }
    vector<pair<int, double>> ans;
    for(auto i : ma){
        ans.push_back({i.first, i.second/100.0});
    }
    sort(ans.begin(), ans.end(), cmp);

    cout<<fixed<<setprecision(2);
    for(auto i : ans)
        cout << i.first << " " << i.second << endl;
}