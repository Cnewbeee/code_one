#include<iostream>

using namespace std;

const int N = 100010;
string w;
int cnt[N], son[N][26], idx;
int n;
char str[N];
void insert(string s){
    int p = 0;
    for(int i = 0; s[i]; i++){
        int u = s[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(string s){
    int p = 0;
    for(int i = 0; s[i]; i ++){
        int u = s[i] - 'A';
        if(!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int i = 0;
    int id = 0;
    while(cin >> w){
        insert(w); 
    }
    cout << idx+1 << endl;
}