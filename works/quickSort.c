#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

const int N = 1e6 + 10;
int f[N];
void quick_sort(int f[], int l, int r)
{
    if(l >= r) return ;

    int x = f[(l+r) >> 1];
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(f[i] < x);
        do j--; while(f[j] > x);
        if(i < j) swap(&f[i], &f[j]);
    }

    quick_sort(f, l, j);
    quick_sort(f, j+1, r);
}

int main()
{
    int n;
    printf("请输入数组长度：\n");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++){
        printf("请输入第%d个元素：\n", i+1);
        scanf("%d", &f[i]);
    }

    printf("\n排序前的数组为：\n");
    for(int i = 0; i < n; i ++){
        printf("%d ", f[i]);
    }
    printf("\n");

    quick_sort(f, 0, n-1);
    
    printf("\n排序后的数组为：\n");
    for(int i = 0; i < n; i ++){
        printf("%d ", f[i]);
    }
    printf("\n");
    return 0;
}

