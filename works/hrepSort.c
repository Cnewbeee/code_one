#include <stdio.h>

const int N = 100010;

int h[N];
int ph[N], hp[N];
int len = 0;
int n, m;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heap_swap(int x, int y){
    swap(&ph[hp[x]], &ph[hp[y]]);
    swap(&hp[x], &hp[y]);
    swap(&h[x], &h[y]);
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

    printf("请输入数组长度：");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("请输入第%d个元素：\n", i);
        scanf("%d", &h[i]);
    }

    len = n;

    for(int i = n/2; i; i--){
        down(i);
    }

    printf("排序结果：");
    for(int i = 0; i < n; i++){
        swap(&h[0], &h[len]);
        len--;
        down(1);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", h[i]);
    }

    return 0;
}