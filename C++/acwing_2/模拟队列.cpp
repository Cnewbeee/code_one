#include<iostream>

using namespace std;

const int N = 100010;

int a[N], tt = 0, hh = -1;

int main(){
    int m = 0;
    cin >> m;

    while(m--){
        string s;
        int x;
        cin >> s;

        if(s == "push"){
            cin >> x;
            a[++hh] = x;
        }
        else if(s == "pop"){
            tt++;
        }
        else if(s == "empty"){
            if(tt > hh)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            cout << a[tt] << endl;
        }
    }
}