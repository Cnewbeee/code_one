#include<bits/stdc++.h>

using namespace std;

int a[5], b[5];
string s[5];

int main(){
    for(int i = 0; i < 5; i++){
        cin >> s[i] >> a[i] >> b[i];
    }

    vector<string> ans;

    for(char x = 'A'; x <= 'Z'; x++){
        for(char y = 'A'; y <= 'Z'; y++){
            for(char z = 'A'; z <= 'Z'; z++){
                bool ok = 1;
                for(int i = 0; i < 5; i++){
                    int c1 = 0, c2 = (s[i][0] == x) + (s[i][1] == y) + (s[i][2] == z);
                    for(char c : s[i]){
                        if(c == x || c == y || c == z)
                            c1++;
                    }
                    if(c1 != a[i] || c2 != b[i]){
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    ans.push_back(string(1, x) + string(1, y) + string(1, z));
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(string ss : ans)
        cout << ss << endl;

    return 0;
}
