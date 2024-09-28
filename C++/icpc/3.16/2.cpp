#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int nw = 0;
        int ori = 0;
        int n;
        string a, b;
        char c;
        cin >> n >> a;
        for(int i = 0; i < n; i++){
            c = a[i];
            a.push_back(c);
            if(c == 'N'){
                b = a.substr(i, 4);
                //cout << b << endl;
                if(b == "NWNU")
                    nw++;
            }
            if(c == 'O'){
                b = a.substr(i, 6);
                //cout << b << endl;
                if(b == "ORIGIN")
                    ori++;
            }
        }
        cout << nw << " " << ori << endl;
    }
    return 0;
}
