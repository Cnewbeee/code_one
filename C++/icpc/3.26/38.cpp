#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e4 + 10;
int n, k;
int a[N];
int an = 0, ans = 0;
int find(int x, int u){
    if(a[x] != x){
        u = find(a[x], u+1);
    }
    return u;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        a[i] = i;
    }

	for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            int t;
            cin >> t;
            a[t] = i;
        }
    }
    int d = 0;
    for(int i = 0; i < n; i++){
        an = find(i, 1);
        if(ans < an){
            ans = an;
            d = i;
        }
    }

    cout << ans << endl;
    stack<int> aaa;
    while(1){
        aaa.push(d);

        if(a[d] != d){
            d = a[d];
        }
        else break;
    }
    cout << aaa.top();
    aaa.pop();
    while(!aaa.empty()){
        cout << " " << aaa.top();
        aaa.pop();
    }
    
	return 0;
}
