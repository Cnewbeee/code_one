#include<iostream>

using namespace std;

const int N = 100010;

int f[N];
int sum[N];
int n, m;

int find(int x){
    if(f[x] == x)return f[x];
    else f[x] = find(f[x]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        f[i] = i;
        sum[i] = 1;
    }

    while(m--){
        char c[2];
        int a, b;
        cin >> c;
        if(c[0] == 'C'){
            cin>> a >> b;
            a = find(a), b =  find(b);
            if(a != b)
                sum[b] += sum[a],
                f[a] = b;
        }
        else if(c[1] == '1'){
            cin >> a >> b;
            if(find(a) == find(b))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            cin >> a;
            cout << sum[find(a)] << endl;
        }
    }
}