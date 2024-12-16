#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10
#define MAX_ 7
#define typeElem char
#define Bool int
#define True 1
#define False 0

typedef struct linkNode{
    int data;
    struct linkNode *next;
}linkNode;

typedef struct node{
    typeElem data;
    linkNode *first;
}listNode;

typedef struct Graph{
    int maxVertex;
    int numEdge;
    int numVertex;
    listNode *pr;
}Graph;

int st[MAXSIZE];

Bool _init(Graph *g){
    g->numEdge = g->numVertex = 0;
    g->maxVertex = MAXSIZE;
    g->pr = (listNode*)malloc(sizeof(listNode)*MAXSIZE);

    if(g->pr == NULL)return False;

    for(int i = 0; i < MAXSIZE; i++){
        g->pr[i].first = NULL;
    }

    return True;
}

void _print(Graph *g){
    printf("\n————————————打印————————————\n\n");
    printf("顶点数: %d\n边总数: %d\n", g->numVertex, g->numEdge);
    for(int i = 0; i < g->numVertex; i++){
        linkNode *p = g->pr[i].first;
        //printf("%d __ %p\n", i, p);
        while(p != NULL){
            printf("%c <---> %c\n", g->pr[i].data, g->pr[p->data].data);
            p = p->next;
        }
    }
    printf("\n————————————————————————————\n\n");
}

Bool _insert(Graph *g, typeElem a, typeElem b){
    int ida = -1, idb = -1, p = 0;

    while(p < g->numVertex){
        if(g->pr[p].data == a){
            ida = p;
        }else if(g->pr[p].data == b){
            idb = p;
        }
        p++;
    }
    if(ida == -1){
        if(g->numVertex >= g->maxVertex)return False;
        g->pr[p].data = a;
        g->pr[p].first = NULL;
        ida = p++;
        g->numVertex++;
    }
    if(idb == -1){
        if(g->numVertex >= g->maxVertex)return False;
        g->pr[p].data = b;
        g->pr[p].first = NULL; 
        idb = p++;
        g->numVertex++;
    }
    //printf("%d_____\n", p);
    linkNode *anode, *bnode;
    anode = (linkNode*)malloc(sizeof(linkNode));
    //bnode = (linkNode*)malloc(sizeof(linkNode));
    anode->data = idb;
    //bnode->data = ida;
    anode->next = g->pr[ida].first;
    //bnode->next = g->pr[idb].first;
    g->pr[ida].first = anode;
    //g->pr[idb].first = bnode;
    g->numEdge++;

    return True;
}

void dfs(Graph *g, int a){
    linkNode *p;
    st[a] = 1;
    printf("%c ", g->pr[a].data);
    p = g->pr[a].first;
    while(p){
        //printf("%d-----%d\n", a, p->data);
        if(!st[p->data])
            dfs(g, p->data);
        p = p->next;
    }
}

void bfs(Graph *g, int a){
    int q[MAXSIZE], hh = 0, tt = -1, p;
    q[++tt] = a;
    while(hh <= tt){
        p = q[hh++];
        st[p] = 1;
        printf("%c ", g->pr[p].data);
        linkNode *pp = g->pr[p].first;
        while(pp){
            if(!st[pp->data])
                q[++tt] = pp->data;
            pp = pp->next;
        }
    }
}

void _test_dfs(Graph *g){
    memset(st, 0, sizeof st);
    printf("————————深度优先遍历————————\n");

    for(int i = 0; i < g->numVertex; i++){
        if(!st[i])
            dfs(g, i);
    }

    printf("\n————————————————————————————\n\n");
}

void _test_bfs(Graph *g){
    memset(st, 0, sizeof st);
    printf("————————广度优先遍历————————\n");


    for(int i = 0; i < g->numVertex; i++){
        if(!st[i])
            bfs(g, i);
    }

    printf("\n————————————————————————————\n\n");
}

void _test_insert(Graph *g){
    typeElem a, b;
    printf("请输入节点1:\n");
    scanf("%c", &a);

    getchar();

    printf("请输入节点2:\n");
    scanf("%c", &b);

    _insert(g, a, b);
    //_insert(g, b, a);
    printf("\n插入成功!\n");
}

void _menu(){
    printf("————————————菜单————————————\n");
    printf("\t1.插入边\n\t2.打印图\n\t3.深度优先遍历\n\t4.广度优先遍历\n\t5.退出\n");
    printf("—————————请输入选项—————————\n");
}

int main(){
    
    Graph g;

    //system("cls");
    printf("——————————初始化图——————————\n");
    _init(&g);
    printf("\n初始化成功!\n\n");
    fflush(stdin);

    int op;

    while(1){
        _menu();
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                _test_insert(&g);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                //system("cls");
                break;
            case 2:
                _print(&g);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                //system("cls");
                break;
            case 3:
                _test_dfs(&g);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                //system("cls");
                break;
            case 4:
                _test_bfs(&g);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                //system("cls");
                break;
            case 5:
                printf("————————————退出————————————\n");
                //fflush(stdin);
                return 0;
            default:
                printf("——————————错误选项——————————\n");
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                //system("cls");
                break;
        }
    }

    return 0;
}