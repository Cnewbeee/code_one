#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010, M = 3100010;
int son[M][2], idx;
int n, a[N];

void insert(int x){
    int p = 0;

    for(int i = 30; ~i; i--){
        int &s = son[p][x >> i & 1];
        if(!s)s = ++idx;
        p = s;
    }
}
int search(int x){
    int res = 0;
    int p = 0;
    for(int i = 30; ~i; i--){
        int s = x >> i & 1;
        if(son[p][!s]){
            p = son[p][!s];
            res += 1 << i;
        }
        else p = son[p][s];
    }
    return res;
}
int main(){
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
        insert(a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, search(a[i]));
    }

    cout << ans << endl;
}