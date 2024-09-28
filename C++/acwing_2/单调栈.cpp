#include<iostream>

using namespace std;

const int N = 100010;

int n;
int st[N], tt;

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        while(tt && st[tt] >= x)tt--;
        if(tt)cout << st[tt] << " ";
        else cout << -1 << " ";
        st[++tt] = x;        
    }
    //for(int i = 0; i < n; i++)cout << st[i] << " ";
    //cout << endl;
}