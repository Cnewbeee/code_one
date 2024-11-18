#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAX_ 7
#define typeElem char
#define Bool int
#define True 1
#define False 0

typedef struct BiTNode{
    typeElem data;
    struct BiTNode *Lchild, *Rchild;
}BiTNode, *BiTree, *Pos;

int cnt = 0, level = 0;

void _Create(BiTree T){

    char ch = 'A';
    Pos q[MAXSIZE];
    int front = 0, rear = 0;
    q[rear++] = T;

    while(front!= rear){
        Pos p = q[front++];
        //printf("%s\n", p);

        p->data = ch++;
        p->Lchild = NULL;
        p->Rchild = NULL;
        
        printf("%c \n", p->data);

        if(ch - 'A' < (MAX_+1)/2){
            p->Lchild = (BiTNode*)malloc(sizeof(BiTNode));
            p->Rchild = (BiTNode*)malloc(sizeof(BiTNode));
            q[rear++] = p->Lchild;
            q[rear++] = p->Rchild;
        }
    }

}

void _visit(BiTNode *p){
    if(p == NULL) return;
    printf("%c ", p->data);
}

void _preorder(BiTNode *p){
    Pos stack[MAXSIZE]; 
    int top = 0;
    stack[top++] = p;

    while(top!= 0){
        p = stack[--top];
        _visit(p);
        if(p->Rchild != NULL) stack[top++] = p->Rchild;
        if(p->Lchild != NULL) stack[top++] = p->Lchild;
    }
}

void _midorder(BiTNode *p){
    Pos stack[MAXSIZE]; 
    int top = 0;
    stack[top++] = p;

    while(top != 0){
        while(p->Lchild != NULL){
            stack[top++] = p->Lchild;
            p = p->Lchild;
        }
        p = stack[--top];
        _visit(p);
        if(p->Rchild != NULL){
            stack[top++] = p->Rchild;
            p = p->Rchild;
        }
        
    }
}

void _postorder(BiTNode *p){
    Pos stack1[MAXSIZE], stack2[MAXSIZE]; 
    int top1 = 0, top2 = 0;
    stack1[top1++] = p;

    while(top1!= 0){
        p = stack1[--top1];
        stack2[top2++] = p;
        if(p->Lchild != NULL) stack1[top1++] = p->Lchild;
        if(p->Rchild != NULL) stack1[top1++] = p->Rchild;

        if(p->Lchild == NULL && p->Rchild == NULL)cnt++;
    }

    while(top2 != 0){
        p = stack2[--top2];
        _visit(p);
    }
}

void _levelorder(BiTNode *p){
    int i, j, k;
    BiTNode *q[MAXSIZE];
    int front = 0, rear = 0;
    q[rear++] = p;

    while(front != rear){
        p = q[front++];
        _visit(p);
        if(p->Lchild != NULL) q[rear++] = p->Lchild;
        if(p->Rchild != NULL) q[rear++] = p->Rchild;
    }
}

void _getlevel(BiTNode *p){
    while(p != NULL){
        level++;
        p = p->Lchild;
    }
}

int main(){
    BiTree T = (BiTree)malloc(sizeof(BiTNode));

    _Create(T);

    printf("前序遍历: ");
    _preorder(T);
    
    printf("\n");

    printf("中序遍历: ");
    _midorder(T);
    
    printf("\n");

    printf("后序遍历: ");
    _postorder(T);
    
    printf("\n");

    printf("层序遍历: ");
    _levelorder(T);
    
    printf("\n");
    printf("共有%d个叶子节点\n", cnt);

    _getlevel(T);
    printf("树的高度为  %d\n", level);

    return 0;
}