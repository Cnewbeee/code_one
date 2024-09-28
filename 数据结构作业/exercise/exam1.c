#include <stdio.h>

typedef struct{
    int num[100];
    int bottom;
    int top;
}_queue;

int push(int n, _queue *p){
    p->num[p->top++] = n;
    //printf("push %d\n", n);
    return 1;
}

int isempty(_queue *p){
    return p->bottom == p->top;
}

int pop(_queue *p, int *n){
    if(isempty(p)) {
        return 0;
    }
    *n = p->num[p->bottom++];
    return 1;
}

int main(){
    _queue a;
    a.bottom = a.top = 0;
    int num = 0, mun = 0, t = 0;
    scanf("%d", &t);
    num = t;
    while(t > 0){
        int s = t % 10;
        push(s, &a);
        t /= 10;
        mun = mun * 10 + s;
    }

    if(mun % num == 0){
        printf("%d=%d*%d\n", mun, num, mun/num);
    }else{
        while(!isempty(&a)){
            int n;
            pop(&a, &n);
            printf("%d", n);
        }
        printf("\n");
    }
}