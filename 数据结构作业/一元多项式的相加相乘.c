#include<stdio.h>
#include<stdlib.h>

#define N 1000
int a[N], b[N], c[N] = {0}, d[N] = {0};
int n, m;

void add(){
    int r = 0;
    for(int i = 0; i < (n > m ? n : m); i++){
        c[i] = a[i] + b[i];
    }

    printf("a + b = \n");

    for(int i = 0; i <= (n > m ? n : m); i++){
        if(c[i] != 0){
            if(r == 0){
                printf("%dx^%d", c[i], i);
                r++;
            }
            else{
                printf(" + %dx^%d", c[i], i);
            }
        }
    }
    printf("\n");
}

void mul(){
    int r = 0, _max = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            d[i+j] += a[i] * b[j];
            if(i + j > _max){
                _max = i + j;
            }
        }
    }

    printf("a * b = \n");

    for(int i = 0; i < _max; i++){
        if(d[i] != 0){
            if(r == 0){
                printf("%dx^%d", d[i], i);
                r++;
            }
            else{
                printf(" * %dx^%d", d[i], i);
            }
        }
    }
    printf("\n");
}

int main(){
    
    printf("请输入一元多项式a的最高项次数：\n");
    scanf("%d", &n);
    printf("请输入一元多项式b的最高项次数：\n");
    scanf("%d", &m);

    for(int i = 0; i <= n; i++){
        printf("请输入a的x^%d项的系数", i);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i <= m; i++){
        printf("请输入b的x^%d项的系数", i);
        scanf("%d", &b[i]);
    }
    
    add();
    mul();
    return 0;
}