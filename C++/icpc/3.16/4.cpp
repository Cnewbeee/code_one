#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int t;
    cin >> s >> t;
    while(t--){
        string a, b, t, d;
        int n, m, q, p;
        cin >> n >> m >> a >> b;
        d = a + b;
        t = s.substr(n, m-n+1);
        //cout << s << "<<<<<<" << endl;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == a[0]){
                string c = s.substr(i, a.size());
                //cout << s << "<<<<<<" << i << endl;
                if(c == a){
                    c = s.substr(i+a.size(), b.size());
                    //cout << c << "<<<<<<" << endl;
                    if(c == b){
                        c = s.substr(i+a.size());
                        
                        s.erase(i+a.size());
                        
                        s = s + t + c;
                        //cout << t << "+" << c << "<<<<<<" << endl;
                        //cout << s << "<<<<<<" << endl;
                        break;
                    }
                }
            }
        }
        //cout << s << "<<<<<<" << endl;
    }
    cout << s;
    return 0;
}
