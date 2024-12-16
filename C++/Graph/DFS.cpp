#include <iostream>
const int N = 1e6+10;
int n;
int path[N];
bool st[N];
using namespace std;
void DFS(int u){
    if(u == n){
        for(int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            st[i] = true;
            path[u] = i;
            DFS(u+1);
            st[i] = false;
        }
    }
}

int main(){
    cin >> n;
    DFS(0);
}