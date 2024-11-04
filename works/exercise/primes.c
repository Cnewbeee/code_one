#include <stdio.h>
#include <stdlib.h>

#define N 1000

int is_prime(int n){
    int i;
    for(i = 2; i*i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, m = 0;
    int pri[10000];
    scanf("%d", &n);

    for(int i = 2; i <= N; i++){
        if(is_prime(i)){
            //printf("%d ", i);
            pri[m++] = i;
        }
    }
    //printf("\n");

    while(n != 1){
        for(int i = 0; i < m; i++){
            if(n % pri[i] == 0){
                n /= pri[i];
                printf("%d ", pri[i]);
                break;
            }
        }
        if(is_prime(n)){
            printf("%d\n", n);
            break;
        }
    }
}