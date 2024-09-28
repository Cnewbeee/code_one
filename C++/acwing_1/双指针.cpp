#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, m, x;
int a[N], b[N];
signed main(void)
{
    cin >> n >> m;
    //cin >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    /*for(int i = 0, j = m-1; i < n; i++){
        while(j >= 0 && a[i] + b[j] > x)j--;
        if(a[i] + b[j] == x){
            cout << i << " " << j << endl;
            break;
        }
    }*/
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j])i++;
        j++;
    }
    if(i == n)cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}
