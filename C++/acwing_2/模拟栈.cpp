#include<iostream>

using namespace std;

const int N = 100010;

int a[N], tt = 0;

int main(){
    int m = 0;
    cin >> m;

    while(m--){
        string s;
        int x;
        cin >> s;

        if(s == "push"){
            cin >> x;
            a[++tt] = x;
        }
        else if(s == "pop"){
            tt--;
        }
        else if(s == "empty"){
            if(tt == 0)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            cout << a[tt] << endl;
        }
    }
}