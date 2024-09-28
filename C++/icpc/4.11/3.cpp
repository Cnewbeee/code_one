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
    string s;
    char c;
    string l;
	while((cin >> c)){
        if(c == '$')break;
        cin >> s;
        if(c == '#'){
            l = s;
            if(f.count(s) == 0)
                f[s] = s;
        }
        else if(c == '+'){
            //Join(l, s);
            f[s] = l;
        }
        else if(c == '?'){
            cout << s << " " << Find(s) << endl;
        }
    }
	
    return 0;
}
