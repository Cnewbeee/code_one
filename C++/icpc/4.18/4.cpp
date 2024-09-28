#include<bits/stdc++.h>

using namespace std;
int n, m;
string ans, s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    getline(cin, s);
    s += " ";
    int len = 0;
    for(int i = 0; i < s.size(); i++){
        if(len == 0 && (s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?'))continue;
        if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?'){
            len %= 10;
            ans.push_back(len + '0');
            len = 0;
        }else{
            len++;
        }
    }
    //if(len > 0)ans.push_back(len + '0');
    cout << ans << endl;
    return 0;

}