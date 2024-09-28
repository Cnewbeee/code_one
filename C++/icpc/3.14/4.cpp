#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

signed main(void)
{
	int n, k;
    cin >> n >> k;
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int ans = 0;
    while(!q.empty()){
        int t;
        t = q.front();
        ans++;

        if(ans == k){
            q.pop();
            cout << t << " ";
            ans = 0;
        }
        else{
            q.pop();
            q.push(t);
        }
    }

	return 0;
}
