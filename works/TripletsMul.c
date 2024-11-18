#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000
#define typeElem int
#define Bool int
#define True 1
#define False 0

typedef struct{
    int col;
    int row;
    typeElem data;
}triplet;

triplet matrix_1[MAXSIZE], matrix_2[MAXSIZE], matrix[MAXSIZE];
int cpos[MAXSIZE] = {0}, ccnt[MAXSIZE] = {0};
int n, m, count=0;

void _print(triplet matrix[]){
    printf("���������������������������ӡ��������������������\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int r = 0;
            for(int k = 1; k <= matrix[0].data; k++){
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
    printf("��������������������������������������������������������\n");
}

Bool _init(triplet matrix_1[]){
    printf("����������������������ʼ�����󡪡���������������\n");
    printf("������������,������");
    scanf("%d%d",&n, &m);

    if(n<=0 || m<=0 || n>MAXSIZE || m>MAXSIZE){
        printf("���������������������Χ��\n");
        return False;
    }
    printf("���������Ԫ�ظ���\n");
    scanf("%d",&count);
    matrix_1[0].row=n;
    matrix_1[0].col=m;
    matrix_1[0].data=count;
    for(int i=1;i<=count;i++){
        printf("�������%d��Ԫ��(�С��С�ֵ):\n",i);
        scanf("%d%d%d",&matrix_1[i].row,&matrix_1[i].col,&matrix_1[i].data);
    }
    _print(matrix_1);
    return True;
}

Bool Mul(triplet matrix_1[], triplet matrix_2[], triplet matrix[]){
    int cnt = 0;
    for(int i = 1; i <= matrix_1[0].row; i++){
        for(int j = 1; j <= matrix_1[0].data; j++){
            if(matrix_1[j].row == i){
                int sum = 0;
                for(int k = 1; k <= matrix_2[0].data; k++){
                    if(matrix_2[k].row == matrix_1[j].col){
                        sum = matrix_1[j].data * matrix_2[k].data;
                        int x = i, y = matrix_2[k].col;
                        //printf("%d * %d = %d\n",matrix_1[j].data,matrix_2[k].data,sum);
                        if(sum!= 0){
                            int r = 0;
                            for(int l = 1; l <= matrix[0].data; l++){
                                if(matrix[l].row == x && matrix[l].col == y){
                                    matrix[l].data += sum; 
                                    r = 1;
                                    break;
                                }
                            }
                            if(r == 0){
                                matrix[cnt+1].row = x;
                                matrix[cnt+1].col = y;
                                matrix[cnt+1].data = sum;
                                cnt++;
                                matrix[0].data++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    _init(matrix_1);
    printf("��ʼ������A�ɹ�!\n\n");

    _init(matrix_2);
    printf("��ʼ������B�ɹ�!\n\n");

    fflush(stdin);
    printf("�����������������س�����ʼ����˷�����()��������������\n");
    getchar();

    printf("����A:\n");
    _print(matrix_1);
    printf("����B:\n");
    _print(matrix_2);
    printf("\n��������������������������������������������������������\n");

    Mul(matrix_1, matrix_2, matrix);
    printf("����˷�������:\n");
    _print(matrix);

    return 0;
}

