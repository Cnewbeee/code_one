#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100 + 10;
int n;
stack<int> st;

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        while(1){
            if(st.size() == 0){st.push(t);break;}
            if(st.top() != t){st.push(t);break;}
            t++;
            //cout << t << endl;
            st.pop();
        }
    }
    cout << st.size() << endl;
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
