#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define Bool int
#define True 1
#define False 0

typedef int elemType;

typedef struct linkNode{
    elemType data;
    struct linkNode *next;
}linkNode;

int _length(linkNode *head){//计算链表长度
    int len = 0;
    linkNode *p = head->next;
    while(p!= NULL){
        len++;
        p = p->next;
    }
    return len;
}

Bool _insert(linkNode *head, int i, elemType elem){//插入节点
    if(i < 1 || i > _length(head)+1){
        return False;
    }
    linkNode *newNode = (linkNode *)malloc(sizeof(linkNode));
    if(newNode == NULL){
        return False;
    }
    newNode->data = elem;

    if(i == 1){
        newNode->next = head->next;
        head->next = newNode;
        return True;
    }else if(i == _length(head)){
        linkNode *p = head ->next;
        while(p->next){
            p = p->next;
        }
        p->next = newNode;
        return True;
    }else{
        int k = 0;
        linkNode *p = head->next;
        while(i != ++k && p->next!= NULL){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
        return True;
    }
    return False;
}

Bool _delete(linkNode *head, int i, elemType *e){//删除节点
    if(i < 1 || i > _length(head)){
        return False;
    }
    if(i == 1){
        linkNode *p = head->next;
        *e = p->data;
        head->next = p->next;
        free(p);
        return True;
    }else if(i == _length(head)){
        linkNode *p = head->next;
        while((p->next)->next){
            p = p->next;
        }
        *e = (p->next)->data;
        free(p->next);
        p->next = NULL;
        return True;
    }else{
        int k = 1;
        linkNode *p = head->next;
        while(i != ++k && p->next!= NULL){
            p = p->next;
        }
        linkNode *q = p->next;
        *e = q->data;
        p->next = q->next;
        free(q);
        return True;
    }
    return False;
}

Bool _search(linkNode *head, int i, elemType *elem){//查找节点
    if(i < 1 || i > _length(head)){
        return False;
    }
    linkNode *p = head->next;
    int k = 0;
    while(i != ++k){
        p = p->next;
    }    
    *elem = p->data;
    return True;
}

void _megenu(linkNode *a, linkNode *b){
    linkNode *p = a->next, *q = b->next, *t = a;

    while(p != NULL && q != NULL){
        printf("111\n");
        if(q->data < p->data){
            t->next = q;
            t = t->next;
            q = q->next;
        }else{
            t->next = p;
            t = t->next;
            p = p->next;
        }
        printf("%d\n", t->data);
    }
    if(p != NULL){
        t->next = p;
    }else if(q != NULL){
        t->next = q;
    }
}

void _print(linkNode *head){//打印链表
    printf("\n————————————打印————————————\n");
    printf("链表长度:%d\n数值域:", _length(head));
    linkNode *p = head->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n————————————————————————————\n\n");
}

void _menu(){
    printf("————————————菜单————————————\n");
    printf("\t1.插入元素\n\t2.删除元素\n\t3.查找元素\n\t4.打印线性表\n\t5.合并线性表\n\t6.退出\n");
    printf("—————————请输入选项—————————\n");
}

void _test_insert(linkNode *L){
    int i, e;
    _print(L);
    printf("———————————元素插入———————————\n");
    while(1){
        printf("请输入插入位置i:");
        scanf("%d", &i);
        printf("请输入插入元素e:");
        scanf("%d", &e);
        if(_insert(L, i, e)){
            printf("————————————成功————————————\n");
            _print(L);
            break;
        }else{
            printf("—————————失败,请重试—————————\n");
        }
    }
}

void _test_delete(linkNode *L){
    int i, e;
    _print(L);
    printf("———————————元素删除———————————\n");
    while(1){
        printf("请输入删除位置i:");
        scanf("%d", &i);
        if(_delete(L, i, &e)){
            printf("删除元素%d成功\n", e);
            _print(L);
            break;
        }else{
            printf("删除元素失败,请重试\n");
        }
    }
}

void _test_search(linkNode *L){
    int i, e;
    printf("———————————元素查找———————————\n");
    while(1){
        printf("请输入查找位置i:");
        scanf("%d", &i);
        if(_search(L, i, &e)){
            printf("元素%d存在\n", e);
            break;
        }else{
            printf("元素不存在,请重试\n");
        }
    }
}

void _test_megenu(linkNode *a, linkNode *b){
    int length_a, length_b;
    printf("—————————合并线性表—————————\n");
    printf("——————初始化线性表a,b———————\n");
    a->next = NULL;
    b->next = NULL;
    _print(a);
    _print(b);
    printf("————————————成功————————————\n");

    printf("请输入线性表a的长度:\n");
    scanf("%d", &length_a);
    printf("请输入线性表a的元素(递增):\n");
    for(int i = 0; i < length_a; i++){
        int e;
        printf("请输入第%d个元素:\n", i+1);
        scanf("%d", &e);
        _insert(a, i+1, e);
    }
    _print(a);
    printf("请输入线性表b的长度:\n");
    scanf("%d", &length_b);
    printf("请输入线性表b的元素(递增):\n");
    for(int i = 0; i < length_b; i++){
        int e;
        printf("请输入第%d个元素:\n", i+1);
        scanf("%d", &e);
        _insert(b, i+1, e);
    }
    _print(b);

    _megenu(a, b);
    printf("合并后的线性表a(a+b):\n");
    _print(a);
}

int main(){
    system("cls");
    printf("————————开始创建链表—————————\n");
    linkNode head, a, b;
    head.next = NULL;
    a.next = NULL;
    b.next = NULL;
    _print(&head);
    printf("————————————成功————————————\n\n");
    printf("———————按回车键继续()———————\n");
    fflush(stdin);
    getchar();
    system("cls");
    while(1){
        _menu();
        int choice = 0;
        //fflush(stdin);
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                _test_insert(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_delete(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_search(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _print(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                _test_megenu(&a, &b);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                printf("————————————退出————————————\n");
                //fflush(stdin);
                return 0;
            default:
                printf("——————————错误选项——————————\n");
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
    }

    return 0;    

}