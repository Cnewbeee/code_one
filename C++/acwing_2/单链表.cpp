#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int e[N], ne[N];
int head, idx;

void inti(){
    head = -1;
    idx = 0;
}
void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    int t;
    cin >> t;

    inti();

    while(t--){
        int x, k;
        char op;

        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head];
            remove(k - 1);
        }else if(op == 'I'){
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        cout << e[i] << " ";
    }
}