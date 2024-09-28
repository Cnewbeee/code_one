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
    int x = 0, y = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'N')y++,cnt1++;
        else if(s[i] == 'S')y--, cnt1++;
        else if(s[i] == 'E')x++, cnt2++;
        else x--, cnt2++;
    }
    //cout << x << " " << y << endl;
    if(x % 2 != 0 || y % 2 != 0 || (x == 0 && y == 0 && n == 2) || n % 2 != 0){
        cout << "NO" << endl;
        return ;
    }
    
    map<char, int> st;
    for(char i : s)st[i]++;
    int a = min(st['N'], st['S']), b = min(st['W'], st['E']);

    if(st['N'] > st['S'])st['N'] -= st['S'], st['S'] = 0;
    else st['S'] -= st['N'], st['N'] = 0; 
    if(st['E'] > st['W'])st['E'] -= st['W'], st['W'] = 0;
    else st['W'] -= st['E'], st['E'] = 0; 
    
    st['W'] /= 2, st['S'] /= 2, st['E'] /= 2, st['N'] /= 2;

    if(a >= 2 || (a >= 1 && b >= 1))st['S']++, st['N']++;
    else if(b >= 2)st['W']++, st['E']++;

    for(int i = 0; i < n; i++){
        if(st[s[i]] > 0){
            st[s[i]]--;
            s[i] = 'R';
        }else{
            s[i] = 'H';
        }
    }
    cout << s << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
