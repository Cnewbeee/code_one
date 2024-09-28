#include<iostream>

using namespace std;

const int N = 100010;

int cnt[N], son[N][26], idx;
int n;
char str[N];
void insert(char *s){
    int p = 0;
    for(int i = 0; s[i]; i++){
        int u = s[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char *s){
    int p = 0;
    for(int i = 0; s[i]; i ++){
        int u = s[i] - 'a';
        if(!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    cin >> n;
    while(n--){
        char c;
        string t;
        cin >> c >> str;
        if(c == 'I'){
            insert(str);
        }
        else {
            cout << query(str) << endl;
        }
    }
}