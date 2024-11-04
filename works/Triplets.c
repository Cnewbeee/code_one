#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000
#define typeElem char
#define Bool int
#define True 1
#define False 0

typedef struct{
    int col;
    int row;
    typeElem data;
}triplet;

triplet matrix_1[MAXSIZE], matrix_2[MAXSIZE];
int cpos[MAXSIZE] = {0}, ccnt[MAXSIZE] = {0};
int n, m, count=0;

void _print(triplet matrix[]){
    printf("———————————矩阵打印——————————\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int r = 0;
            for(int k = 0; k < count; k++){
                if(matrix[k].row == i+1 && matrix[k].col == j+1){
                    printf("%d\t",matrix[k].data);
                    r = 1;
                    break;
                }
            }
            if(r == 0) printf("0\t");
        }
        printf("\n");
    }
    printf("————————————————————————————\n");
}

Bool _init(){
    printf("——————————初始化矩阵—————————\n");
    printf("请输入矩阵的行（列）数：");
    scanf("%d",&n);
    m = n;
    if(n<=0 || m<=0 || n>MAXSIZE || m>MAXSIZE){
        printf("输入的行数或列数超出范围！\n");
        return False;
    }
    printf("请输入矩阵元素个数\n");
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        printf("请输入第%d个元素(行、列、值):\n",i+1);
        scanf("%d%d%d",&matrix_1[i].row,&matrix_1[i].col,&matrix_1[i].data);
    }
    _print(matrix_1);
    return True;
}

Bool _Transpose(){
    for(int i = 0; i < count; i++){
        int col = matrix_1[i].col;
        ccnt[col]++;
    }
    for(int i = 0; i < m; i++){
        cpos[i+1] = cpos[i] + ccnt[i];
    }

    for(int i = 0; i < count; i++){
        int row = matrix_1[i].col;
        int col = matrix_1[i].row;
        int pos = cpos[row];
        matrix_2[pos].row = row;
        matrix_2[pos].col = col;
        matrix_2[pos].data = matrix_1[i].data;
        cpos[row]++;
    }
    _print(matrix_2);
    
    return True;
}

int main(){
    _init();
    printf("初始化成功!\n\n");

    fflush(stdin);
    printf("———————按回车键转置()———————\n");
    getchar();

    _Transpose();
    printf("转置成功!\n\n");

    return 0;
}

