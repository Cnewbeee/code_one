#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 110;
stack<char> ku;
int n, m, k;
//vector<int, queue<char>> a(110);
queue<char> a[110];

vector<char> lu;
void solve()
{
    
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char t;
            cin >> t;
            a[i].push(t);
        }
    }
    int c;
    while(1){
        cin >> c;
        if(c == -1)break;
        if(c == 0){
            if(!ku.empty())
            lu.push_back(ku.top()),ku.pop();
        }
        else if(a[c].empty()){
            continue;
        }
        else if(ku.size() >= k){
            lu.push_back(ku.top());//cout << ku.top() << endl;
            ku.pop();
            ku.push(a[c].front());
            a[c].pop();
        }
        else{
            ku.push(a[c].front());
            a[c].pop();
        }
    }
    for(auto i : lu){
        cout << i;
    }
	return 0;
}
