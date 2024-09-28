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
        for(int i = 0; i < s.size() - b.size() - a.size(); i++){
            if(a == s.substr(i, a.size()) && b == s.substr(i+a.size(), b.size())){
                s = s.substr(0, i+a.size()) + t + s.substr(i+a.size(), s.size()-i-s.size());
            }
        }
        //cout << s << "<<<<<<" << endl;
    }
    cout << s;
    return 0;
}
