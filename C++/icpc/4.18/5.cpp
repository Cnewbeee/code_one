#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
int n, m;
vector<PII> a;
map<int, int> mp;
bool cmp(PII a, PII b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(PII(x, i+1));
        mp[i+1] = x;
    }
    sort(a.begin(), a.end(), cmp);
    //for(int i = 0; i < n; i++)cout << a[i].first << " " << a[i].second << endl;
    int x, y;
    cin >> x >> y;

    int son = ceil((mp[x] + mp[y]) / 2);
    int l = 0;
    //cout << son << endl;
    for(int i = 0; i < n; i++){
        if(a[i].first >= son){
            l = i;
            break;
        }
    }
    if(abs(a[l].first - son) > abs(a[l-1].first - son))l--;
    else if(abs(a[l].first - son) == abs(a[l-1].first - son)){
        if(a[l].second > a[l-1].second)l--;
    }
    //cout << l << endl;
    int ans = a[l].second;
    cout << ans << endl;
    return 0;

}