#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<string,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
map<string, int> m;
bool cmp(PII x, PII y){
    if(x.second > y.second) return true;
    else if(x.second < y.second) return false;
    else if(x.first < y.first) return true;
    else return false;
}

signed main(void)
{
	int n, g;
    cin >> n >> g;

    int h;
    int cot = 0, sum = 0;
    while(n--){
        string t;
        cin >> t >> h;
        if(h >= g){
            m[t] += 50;
            sum += 50;
        }
        else if(h >= 60){
            m[t] += 20;
            sum += 20;
        }
        else{
            cot ++;
        }
    }
    cout << sum << endl;
    if(cot >= 5){
        cout << "(＞﹏＜)";
        return 0;
    }
    vector<PII> pi;
    for(auto i : m){
        pi.push_back({i.first, i.second});
    }
    sort(pi.begin(), pi.end(), cmp);
    for(auto j : pi){
        cout << j.first << ' ' << j.second << endl;
    }
	return 0;
}
