#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N];
int ph[N], hp[N];
int len = 0;
void heap_swap(int x, int y){
    swap(ph[hp[x]],ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}
void down(int u){
    int t = u;
    if(u*2 <= len && h[u*2] < h[t])t = u*2;
    if(u*2+1 <= len && h[u*2+1] < h[t])t = u*2+1;
    if(u != t){
        heap_swap(t, u);
        down(t);
    }
}
void up(int u){
    int t = u;
    while(u/2 && h[u/2] > h[u]){
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main(){
    int n = 0, m = 0;
    
    scanf("%d", &n);

    char s[5];
    while(n--){
        scanf("%s", s);
        int x, k;
        if(s[0] == 'I'){
            scanf("%d", &x);
            len++;
            m++;
            ph[m] = len;
            hp[len] = m;
            h[len] = x;
            up(len); 

        }else if(s[0] == 'P'){
            printf("%d\n", h[1]);

        }else if(s[0] == 'D' && s[1] == 'M'){
            heap_swap(1, len);
            len--;
            down(1);
            
        }else if(s[0] == 'D'){
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, len);
            len--;
            up(k);
            down(k);

        }else{
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);

        }
    }
    return 0;
}