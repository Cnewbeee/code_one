#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define typeElem int
#define Bool int
#define True 1
#define False 0

typedef struct OLNode{
    typeElem data;
    int row;
    int col;
    struct OLNode *right, *down;
}OLNode, *Link;

typedef struct{
    Link *rhead, *chead;
    int row, col, size;
}crossList;

Bool initCrossList(crossList *cl){
    cl->rhead = (Link*)malloc(MAXSIZE*sizeof(Link));
    cl->chead = (Link*)malloc(MAXSIZE*sizeof(Link));

    for(int i = 0; i < MAXSIZE; i++){
        cl->rhead[i] = cl->chead[i] = NULL;
    }

    cl->row = cl->col = cl->size = 0;
    return True;
}

Bool insert(crossList *cl, typeElem data, int row, int col){
    Link newnode = (Link)malloc(sizeof(OLNode));
    newnode->data = data;
    newnode->row = row;
    newnode->col = col;
    newnode->right = newnode->down = NULL;
    if(cl->size == 0){
        cl->rhead[row] = cl->chead[col] = newnode;
        cl->row = row;
        cl->col = col;
    }
    else{
        if(cl->row < row)cl->row = row;
        if(cl->col < col)cl->col = col;

        if(cl->rhead[row] == NULL || col < cl->rhead[row]->col){
            newnode->right = cl->rhead[row];
            cl->rhead[row] = newnode;
        }else{
            Link p = cl->rhead[row];
            while(p->right != NULL){
                if(p->right->col > col){
                    newnode->right = p->right;
                    p->right = newnode;
                    break;
                }
                p = p->right;
            }
            if(p->right == NULL){
                p->right = newnode;
            }
        }
        if(cl->chead[col] == NULL || row < cl->chead[col]->row){
            newnode->down = cl->chead[col];
            cl->chead[col] = newnode;
        }else{
            Link p = cl->chead[col];
            while(p->down != NULL){
                if(p->down->row > row){
                    newnode->down = p->down;
                    p->down = newnode;
                    break;
                }
                p = p->down;
            }
            if(p->down == NULL){
                p->down = newnode;
            }
        }
    }
    cl->size++;
    //printf("row: %d, col: %d, data: %d\n", row, col, data);
    return True;
}

Bool add(crossList *cl_1, crossList *cl_2, crossList *cl){
    Link q, p;
    int r = cl_1->row > cl_2->row ? cl_1->row : cl_2->row;
    int c = cl_1->col > cl_2->col ? cl_1->col : cl_2->col;
    //printf("11111\n");

    for(int i = 1; i <= r; i++){
        //printf("%d\n", i);
        q = cl_1->rhead[i];
        p = cl_2->rhead[i];
        while(p != NULL || q != NULL){
            //printf("11111\n");
            if(p != NULL && q != NULL && p->col != q->col){
                //printf("111\n");
                insert(cl, p->data, i, p->col);
                insert(cl, q->data, i, q->col);
                p = p->right;
                q = q->right;
            }else if(p != NULL && q != NULL && p->col == q->col){
                //printf("222\n");
                insert(cl, q->data+p->data, i, q->col);
                p = p->right;
                q = q->right;
            }else if(q != NULL){
                //printf("333\n");
                insert(cl, q->data, i, q->col);
                q = q->right;
            }else if(p != NULL){
                //printf("444\n");
                insert(cl, p->data, i, p->col);
                p = p->right;
            }
        }
    }
}

void printCrossList(crossList *cl){
    int i, j;
    printf("\n———————————矩阵打印——————————\n\n");
    for(i = 1; i <= cl->row; i++){
        Link p = cl->rhead[i];
            while(p != NULL){
                printf("row: %d, col: %d, data: %d\n", p->row, p->col, p->data);
                p = p->right;
            }
    }
    printf("\n————————————————————————————\n");

}

int main(){
    crossList cl, cl_1, cl_2;
    initCrossList(&cl);
    initCrossList(&cl_1);
    initCrossList(&cl_2);
    int n;    
    printf("——————————初始化矩阵A—————————\n");
    printf("请输入矩阵A的元素个数：\n");

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int c, r, d;
        printf("请输入第%d个元素的行、列、值：\n", i+1);
        scanf("%d%d%d", &r, &c, &d);
        insert(&cl_1, d, r, c);
    }
    printCrossList(&cl_1);

    printf("——————————初始化矩阵B—————————\n");
    printf("请输入矩阵B的元素个数：\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int c, r, d;
        printf("请输入第%d个元素的行、列、值：\n", i+1);
        scanf("%d%d%d", &r, &c, &d);
        insert(&cl_2, d, r, c);
    }
    printCrossList(&cl_2);

    printf("\n————————————————————————————\n\n");

    add(&cl_1, &cl_2, &cl);
    printf("————————————矩阵C———————————\n");
    printCrossList(&cl);
    
    return 0;
}
