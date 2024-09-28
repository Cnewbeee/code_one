#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x){
    int k = (x % N + N) % N;

    while(h[k] != null && h[k] != x){
        k++;
        if(k == N)k = 0;
    }
    return k;
}

int main(){
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h);

    while(n--){
        char op[2];
        int x;
        cin >> op >> x;
        int k = find(x);
        if(op[0] == 'I'){
            h[k] = x;
        }
        else {
            if(h[k] == x)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}