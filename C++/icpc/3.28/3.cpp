#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
vector<int> a;
int erfen(int l, int r, int x){
    while(l < r){
        int mid = l + r >> 1;

        if(a[mid] >= x) r = mid;
        else l = mid+1;
    }
    return l;
}


signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
    cin >> n;
    

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }

    for(int i = 0; i < n-1; i++){
        int l = i+1;
        int r = n-1;
        l = erfen(l, r, a[i]);
        if(a[l] <= a[i])cout << 0 << " ";
        else cout << l+1 << " ";
    }
    cout << 0;
	return 0;
}
