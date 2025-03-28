#include <stdio.h>
#include <stdlib.h>

#define MAX_ 100

int arr[MAX_], len = 1, dk[MAX_], len_dk = 0;

void shellSort(int n) {
    int k;
    for(int i = n + 1; i <= len; i++){
        arr[0] = arr[i];
        k = i - n;
        while(k > 0 && arr[k] > arr[0]){
            arr[k+n] = arr[k];
            arr[k] = arr[0];
            k = k - n;
        }
    }
}

void shell(){
    for(int i = 0; i < len_dk; i++){
        shellSort(dk[i]);
    }
}

void getdk(){
    int start = (len - 2) / 2 * 2 + 1;

    for(int i = start; i >= 1; i -= 2){
        //printf("dk[%d] = %d\n", len_dk, i);
        dk[len_dk++] = i;
    }
}

int main(){

    printf("请输入数组长度:\n");
    scanf("%d", &len);

    for(int i = 1; i <= len; i++){
        int num;
        printf("请输入插入的元素:\n");
        scanf("%d", &num);

        arr[i] = num;

        printf("成功插入了%d\n", num);
    }

    printf("\n排序前的数组:\n");
    for(int i = 1; i <= len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    getdk();
    shell();
    
    printf("排序后的数组:\n");
    for(int i = 1; i <= len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
