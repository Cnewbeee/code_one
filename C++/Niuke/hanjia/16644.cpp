#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

bool iss(char c){
    return c >= 'a' && c <= 'z';
}

bool isd(char c){
    return c >= '0' && c <= '9';
}

void solve()
{
    int p1, p2, p3;
    string a, ans;
    cin >> p1 >> p2 >> p3 >> a;
    int t = 0;
    if(p1 == 1){
        if(p3 == 1){
            for(int i = 1; i < a.length(); i++){
                if(a[i] == '-' && a[i-1] < a[i+1] && (iss(a[i-1]) && iss(a[i+1]) || isd(a[i-1]) && isd(a[i+1]))){
                    ans += a.substr(t, i-t);
                    //cout << t << " " << i-t << " " << ans << endl;
                    for(char j = a[i-1]+1; j < a[i+1]; j++){
                        for(int k = 0; k < p2; k++){
                            ans.push_back(j);
                        }
                    }t = i+1;
                }
                
            }
        }else{
             for(int i = 1; i < a.length(); i++){
                if(a[i] == '-' && a[i-1] < a[i+1] && (iss(a[i-1]) && iss(a[i+1]) || isd(a[i-1]) && isd(a[i+1]))){
                    ans += a.substr(t, i-t);
                    for(char j = a[i+1]-1; j > a[i-1]; j--){
                        for(int k = 0; k < p2; k++){
                            ans.push_back(j);
                        }
                    }t = i+1;
                }
                
            }
        }
    }else if(p1 == 2){
        if(p3 == 1){
            for(int i = 1; i < a.length(); i++){
                if(a[i] == '-' && a[i-1] < a[i+1] && (iss(a[i-1]) && iss(a[i+1]) || isd(a[i-1]) && isd(a[i+1]))){
                    ans += a.substr(t, i-t);
                    for(char j = a[i-1]+1; j < a[i+1]; j++){
                        for(int k = 0; k < p2; k++){
                            if(iss(j))ans.push_back(j-32);
                            else ans.push_back(j);
                        }
                    }t = i+1;
                }
                
            }
        }else{
             for(int i = 1; i < a.length(); i++){
                if(a[i] == '-' && a[i-1] < a[i+1] && (iss(a[i-1]) && iss(a[i+1]) || isd(a[i-1]) && isd(a[i+1]))){
                    ans += a.substr(t, i-t);
                    for(char j = a[i+1]-1; j > a[i-1]; j--){
                        for(int k = 0; k < p2; k++){
                            if(iss(j))ans.push_back(j-32);
                            else ans.push_back(j);
                        }
                    }t = i+1;
                }
                
            }
        }
    }else{
        for(int i = 1; i < a.length(); i++){
            if(a[i] == '-' && a[i-1] < a[i+1] && (iss(a[i-1]) && iss(a[i+1]) || isd(a[i-1]) && isd(a[i+1]))){
                ans += a.substr(t, i-t);
                for(char j = a[i-1]+1; j < a[i+1]; j++){
                    for(int k = 0; k < p2; k++){
                        ans.push_back('*');
                    }
                }t = i+1;
            }    
        }
    }
    ans += a.substr(t);
    cout << ans;
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