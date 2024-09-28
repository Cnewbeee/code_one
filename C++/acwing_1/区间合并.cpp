#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
vector<PII> segs;
int n;
void megre(vector<PII> &segs){
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int ed = -2e9, st = -2e9;
    for(auto seg : segs){
        if(ed < seg.first){
            if(st != -2e9) res.push_back({st, ed});
            ed = seg.second;
            st = seg.first;
        }
        else{
            ed = max(ed, seg.second);
        }
    }
    if(st != -2e9) res.push_back({st, ed});
    segs = res;
}

signed main(void)
{   
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    megre(segs);

    cout << segs.size() << endl;
	return 0;
}
