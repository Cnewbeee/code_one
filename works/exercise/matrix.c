#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
    int a[N][N];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    char op;

    while(1){
        scanf("%c", &op);
        if(op == '#'){
            break;
        }else if(op == '+'){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int b;
                    scanf("%d", &b);
                    a[i][j] += b;
                }
            }
        }else if(op == '-'){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    int b;
                    scanf("%d", &b);
                    a[i][j] -= b;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}