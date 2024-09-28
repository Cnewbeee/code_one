#include <stdio.h>

int isPrimenum(int n){
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}



int main(){
    int num_ = 0, a = 0, num = 0;

    scanf("%d", &a);
    num_ = a;

    while(a > 0){
        int s = a % 10;
        a /= 10;
        num = num * 10 + s;
    }
    
    if(isPrimenum(num) && isPrimenum(num_)){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}