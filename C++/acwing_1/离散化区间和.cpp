#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 300010;
int a[N], s[N];
vector<int> alls;
vector<PII> add, quire;

int find(int x){
    int l = 0, r = alls.size()-1;

    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid+1;
    }
    return r+1;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;

        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        quire.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto i : add){
        int x = find(i.first);
        a[x] += i.second;
    }
    for(int i = 1; i <= alls.size(); i++){
        s[i] = a[i] + s[i-1];
    }
    for(auto i : quire){
        int l = find(i.first);
        int r = find(i.second);
        
        cout << s[r] - s[l-1] << endl;
    }
	return 0;
}
