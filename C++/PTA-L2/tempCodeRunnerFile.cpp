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
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    string str;
    getline(cin, str);
    int ans = 0;

    for(int i = 0; i < str.size(); i++){
        for(int j = str.size()-1; j >= i+1; j--){
            int l = i, r = j;
            int res = 1;
            while(l < r){
                if(str[l] == str[r]){ 
                    //cout << str.substr(l, r-l+1) << endl;
                    l++, r--;
                }
                else {
                    res = 0;
                    break;
                }
            }
            if(res == 1){
                //cout << str.substr(l, r-l+1) << endl;
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans << endl;

	return 0;
}
