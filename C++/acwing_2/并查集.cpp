#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int n, m;
int f[N];
int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void join(int x, int y){
    f[find(y)] = find(f[x]);
}

signed main(void)
{
    cin >> n >> m;
    char t;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    while(m--){
        int x, y;
        cin >> t >> x >> y;

        if(t == 'M'){
            join(x, y);
        }
        else{
            if(find(x) == find(y)){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
	

	return 0;
}
