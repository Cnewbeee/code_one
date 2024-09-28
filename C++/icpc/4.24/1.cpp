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
    vector<int> a, A, num;

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            a.push_back(i);
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            A.push_back(i);
        }else{
            num.push_back(i);
        }
    }
    if(a.size() && A.size() && num.size());
    else if(a.size() && A.size()){
        for(int i = 0; i < s.size(); i++){
            if(i != a[0] && i != A[0]){
                s[i] = '0';
                break;
            }
        }
    }else if(a.size() && num.size()){
        for(int i = 0; i < s.size(); i++){
            if(i != a[0] && i != num[0]){
                s[i] = 'A';
                break;
            }
        }
    }else if(A.size() && num.size()){
        for(int i = 0; i < s.size(); i++){
            if(i != num[0] && i != A[0]){
                s[i] = 'a';
                break;
            }
        }
    }else if(a.size()){
        s[1] = 'A';
        s[2] = '0';
    }else if(A.size()){
        s[1] = 'a';
        s[2] = '0';
    }else if(num.size()){
        s[1] = 'a';
        s[2] = 'A';
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
