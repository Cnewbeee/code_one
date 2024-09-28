#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
vector<PII> ans;
int f[N], p[N];
void quick_sort(int f[], int l, int r)
{
    if(l >= r) return ;

    int x = f[(l+r) >> 1];
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(f[i] < x);
        do j--; while(f[j] > x);
        if(i < j) swap(f[i], f[j]), ans.push_back({i, j});
    }

    quick_sort(f, l, j);
    quick_sort(f, j+1, r);
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> f[i];
        p[f[i]] = i;
    }
    //wquick_sort(f, 1, n);

    for(int i = 1; i <= n; i++){
        if(f[i] == i)continue;
        swap(f[i], f[p[i]]);
        ans.push_back({p[i], i});
        
        p[f[p[i]]] = p[i];
        p[i] = i;
    }
    //for(int i = 1; i <= n; i++)cout << p[i] << " " ;
    //cout << endl;
    cout << ans.size() << endl;
    for(PII i : ans){
        cout << i.first << " " << i.second << endl;
    }
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
