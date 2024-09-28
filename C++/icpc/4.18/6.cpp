#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
int n, m;
string an;
string s[110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> an;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    if(an[0] == 'S'){
        for(int i = 0; i < n; i++){
            string ans;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
                    if(j == 0){
                        ans.push_back(s[i][j] + 32);
                    }else{
                        ans.push_back('_');
                        ans.push_back(s[i][j] + 32);
                    }
                }else{
                    ans.push_back(s[i][j]);
                }
            }
            cout << ans << endl;
        }
    }else if(an[0] == 'P'){
        for(int i = 0; i < n; i++){
            string ans;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
                    ans.push_back(s[i][j]);
                }else if(s[i][j] == '_'){
                    continue;
                }else{
                    if(j == 0)ans.push_back(s[i][j] - 32);
                    else if(s[i][j-1] == '_')ans.push_back(s[i][j] - 32);
                    else ans.push_back(s[i][j]);;
                }
            }
            cout << ans << endl;
        }
    }else if(an[0] == 'C'){
        for(int i = 0; i < n; i++){
            string ans;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
                    if(j == 0)ans.push_back(s[i][j] + 32);
                    else ans.push_back(s[i][j]);
                }else if(s[i][j] == '_'){
                    continue;
                }else{
                    if(s[i][j-1] == '_')ans.push_back(s[i][j] - 32);
                    else ans.push_back(s[i][j]);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;

}
/*4 Cooo
userName
Password
background_color
text*/