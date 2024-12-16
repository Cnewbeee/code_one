#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

void _getlevel(BiTNode *p, int l){
    if(l > level) level = l;
    if(p == NULL) return;
    _getlevel(p->Lchild, l+1);
    _getlevel(p->Rchild, l+1);
}

void _Create(BiTree T){

    char ch = 'A';
    Pos q[MAXSIZE];
    int front = 0, rear = 0;
    q[rear++] = T;
    int l = 0, le = 0;

    while(front!= rear){
        Pos p = q[front++];
        //printf("%s\n", p);

        p->data = ch++;
        p->Lchild = NULL;
        p->Rchild = NULL;
        
        le = log((int)(ch - 'A' + 1)) / log(2);
        
        printf("%c\t", p->data);
        if(le > l){
            printf("\n");
        }
        l = le;

        if(ch - 'A' < (MAX_+1)/2){
            p->Lchild = (BiTNode*)malloc(sizeof(BiTNode));
            p->Rchild = (BiTNode*)malloc(sizeof(BiTNode));
            q[rear++] = p->Lchild;
            q[rear++] = p->Rchild;
        }
    }

}

Bool _insert(BiTree T, typeElem e, Bool flag){
    if(flag == True){
        T->Lchild = (BiTNode*)malloc(sizeof(BiTNode));
        T->Lchild->data = e;
        T->Lchild->Lchild = NULL;
        //printf("%p L\n", T->Lchild->Lchild);
        T->Lchild->Rchild = NULL;
        //printf("%p R\n", T->Lchild->Rchild);

        //printf("%p ", T->Lchild);
        printf("%c 的左孩子节点 %c 插入成功\n", T->data, T->Lchild->data);
    }else{
        T->Rchild = (BiTNode*)malloc(sizeof(BiTNode));
        T->Rchild->data = e;
        T->Rchild->Lchild = NULL;
        //printf("%p L\n", T->Lchild->Lchild);
        T->Rchild->Rchild = NULL;
        //printf("%p R\n", T->Lchild->Rchild);

        //printf("%p ", T->Rchild);
        printf("%c 的右孩子节点 %c 插入成功\n", T->data, T->Rchild->data);
    }
    return True;
}

void _visit(BiTNode *p){
    if(!p) return;

    //printf("%p ", p);
    printf("%c ", p->data);
}

void _preorder(BiTree t){
    Pos stack[MAXSIZE]; 
    Pos p = t;
    int top = 0;
    stack[top++] = p;

    while(top != 0){
        p = stack[--top];

        _visit(p);
        if(p->Rchild) stack[top++] = p->Rchild;
        if(p->Lchild) stack[top++] = p->Lchild;
    }
}

void _midorder(BiTree T){
    Pos stack[MAXSIZE]; 
    int top = 0, r = 0;
    Pos p = T;
    //stack[top++] = p;

    while(top != 0 || p!= NULL){
        //r = 1;
        if(p){
            stack[top++] = p;
            p = p->Lchild;
        }else{
            p = stack[--top];
            _visit(p);
            p = p->Rchild;
        }
    }
}

void _postorder(BiTNode *p){
    Pos stack1[MAXSIZE], stack2[MAXSIZE]; 
    int top1 = 0, top2 = 0;
    stack1[top1++] = p;

    while(top1 != 0){
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

Pos _search(BiTree T, typeElem e){
    if(T == NULL || T->data == e) return T;
    //printf("%c\n", e);
    Pos stack[MAXSIZE]; 
    Pos p = T;
    int top = 0;
    stack[top++] = p;

    while(top != 0){
        p = stack[--top];

        if(p->data == e) return p;
        if(p->Rchild) stack[top++] = p->Rchild;
        if(p->Lchild) stack[top++] = p->Lchild;
    }
    return NULL;
}

void _print(BiTree T){

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

Bool _test_insert(BiTree T){
    char ch = 'B';
    
    Pos p = T;
    int op = 0;

    while(1){
        
        printf("——————————————插入——————————————\n");

        Pos node;
        char c;

        printf("层序遍历: ");
        _levelorder(T);
        printf("\n");

        printf("请输入插入节点() 或者 退出(1)\n");
        scanf("%c", &c);
        //printf("%c___\n", c);
        //getchar();

        if(c == '1')break;

        node = _search(T, c);

        //printf("%c\n", node->data);
        if(node == NULL){
            printf("未找到该节点, 请重新输入!\n");
            continue;
        }
        
        printf("请选择插入1:左子树, 2:右子树\n");
        scanf("%d", &op);

        if(op == 1){
            _insert(node, ch++, True);
            printf("左子树插入成功!\n");
        }else if(op == 2){
            _insert(node, ch++, False);
            printf("右子树插入成功!\n");
        }else{
            printf("输入错误, 请重新输入!\n");
            continue;
        }
        fflush(stdin);
        printf("————————————————————————————————\n\n");
    }
    return True;
}

int main(){

    printf("——————————初始化根节点——————————\n");

    BiTree T = (BiTNode*)malloc(sizeof(BiTNode));
    T->data = 'A';
    T->Lchild = NULL;
    T->Rchild = NULL;

    //printf("rr:%p \n", T->Rchild);
    //printf("%c \n", T->data);
    //_Create(T);

    printf("初始化成功!\n\n");

    _test_insert(T);

    printf("\n前序遍历: ");
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

    _getlevel(T, 0);
    printf("树的高度为  %d\n", level);

    return 0;
}