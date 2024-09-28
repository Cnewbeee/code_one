#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PIS pair<string, string>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
map<string, string> f;
string Find(string a)
{
    if(f[a] == a) return f[a];
    else return f[a] = Find(f[a]);
}
void Join(string a, string b)
{
    f[Find(b)] = Find(a);
}
signed main(void)
{
	int n, m;
	cin >>n >> m;

	for(int i = 0; i <n; i ++)
    {
        string t;
        cin >> t;
        f[t] = t;
    }
    for(int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        Join(a, b);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++)
    {
        string x, y;
        cin >> x >> y;
        if(Find(x) == Find(y))
        {
            cout << "Yes." << endl;
        }
        else
        {
            cout << "No." << endl;
        }
    }
	return 0;
}
