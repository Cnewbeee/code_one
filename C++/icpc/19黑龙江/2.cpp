#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    string s;
    cin >> s;
    map<int, int> se;
    while(1){
        if(s.size() < 3)break;
        int rr = 1;
        for(int i = 0; i < 26; i++){
            if(se[i])continue;
            string t;
            t.push_back('a'+i);t.push_back('a'+i);t.push_back('a'+i);
            int index = s.find(t);
            if(index != string::npos){
                int l = index - 1, r = index + 3;
                while(1){
                    if(l < 0 || r >= s.size())break;
                    int res = 0;
                    if(l >= 0 && s[l] == s[l-1] && s[l] == s[r]) res = -1;
                    else if(r < s.size()-1 && s[r] == s[r+1] && s[l] == s[r]) res = 1;
                    if(res == 0)break;
                    if(res == -1)l -= 2, r += 1;
                    else l -= 1, r += 2;
                }
                //cout << r-l-1 << endl;
                s.erase(l+1, r-l-1);
                rr = 0;
                break;
            }else{
                se[i]++;
            }
            if(s.size() < 3){rr = 1;break;}
        }
        if(rr)break;
    }
    if(s.empty()) cout << "NAN" << endl;
    else cout << s << endl;
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
