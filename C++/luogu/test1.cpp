#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.size() == 5 && s[2] == s[4]){
            int r = 0;
            map<char, int> ma;
            for(int j = 0; j < 4; j++){
                char t = s[j];
                ma[t]++;
                if(ma[t] >= 2){
                    r = 1;
                    break;
                }
            }
            if(r == 0)ans ++;
        }
    }

    cout << ans << endl;
    
	return 0;
}
