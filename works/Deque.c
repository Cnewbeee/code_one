#include <stdio.h>
#include <stdlib.h>

#define typeElem int
#define Bool int
#define True 1
#define False 0

typedef struct Dequenode{
    typeElem data;
    struct Dequenode *ne;
    struct Dequenode *pr;
}Dequenode;

typedef struct Deque{
    Dequenode *head;
    Dequenode *tail;
    int size;
}Deque;

Bool _init(Deque *d){
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
    return True;
}

Bool _destroy(Deque *d){
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
    return True;
}

Bool _isEmpty(Deque *d){
    return d->size == 0;
}

Bool _push(Deque *d, typeElem e, int op){
    Dequenode *newNode = (Dequenode*)malloc(sizeof(Dequenode));
    newNode->data = e;
    newNode->ne = NULL;
    if(_isEmpty(d)){
        d->head = newNode;
        d->tail = newNode;
    }else if(op == 1){//尾插
        d->tail->ne = newNode;
        newNode->pr = d->tail;
        d->tail = newNode;
    }else{//头插
        d->head->pr = newNode;
        newNode->ne = d->head;
        d->head = newNode;
    }
    d->size++;
    return True;
}

Bool _pop(Deque *d, typeElem *e, int op){
    if(_isEmpty(d)){
        return False;
    }
    if(d->size == 1){
        *e = d->head->data;
        d->head = NULL;
        d->tail = NULL;
    }else if(op == 0){//头出队
        *e = d->head->data;
        d->head = d->head->ne;
        d->head->pr = NULL;
    }else{
        *e = d->tail->data;
        d->tail = d->tail->pr;
        d->tail->ne = NULL;
    }
    
    d->size--;
    return True;
}

typeElem _length(Deque *d){
    return d->size;
}

Bool _getHead(Deque *d, typeElem *e){
    if(d->size == 0){
        return False;
    }

    *e = d->head->data;

    return True;
}

Bool _getTail(Deque *d, typeElem *e){
    if(d->size == 0){
        return False;
    }
    
    *e = d->tail->data;

    return True;
}

void _print(Deque *d){
    Dequenode *temp = d->head;
    printf("\n————————————打印————————————\n");
    typeElem h, t;
    if(!_isEmpty(d)){
        _getHead(d, &h);
        _getTail(d, &t);
        printf("\n队长:%d\n队首元素: %d\n队尾元素: %d\n", _length(d), h, t);
        printf("数值域为：\n");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->ne;
        }
        printf("\n");
    }else
        printf("\n队为空!\n");
    printf("\n————————————————————————————\n\n");
}

void _menu(){
    printf("————————————菜单————————————\n");
    printf("\t1.队首压入元素\n\t2.队尾压入元素\n\t3.弹出队首\n\t4.弹出队尾\n\t5.打印\n\t6.清空队\n\t7.退出\n");
    printf("—————————请输入选项—————————\n");
}

void _test_push(Deque *d, int op){
    typeElem e;
    _print(d);
    Bool r;
    printf("——————————压入元素——————————\n");
    printf("请输入压入元素e:");
    scanf("%d", &e);
    r = _push(d, e, op);
    if(r){
        printf("————————————成功————————————\n");
        _print(d);
    }else{
        printf("———————失败,队未初始化———————\n");
    }
}

void _test_pop(Deque *d, int op){
    typeElem e;
    _print(d);
    printf("————————————弹出————————————\n");
    Bool r;
    r = _pop(d, &e, op);
    if(r){
        if(op == 0)
            printf("\n弹出队首 %d 成功\n", e);
        else
            printf("\n弹出队尾 %d 成功\n", e);
        _print(d);
    }else{
        printf("———————弹出元素失败,队为空——————\n");
    }
}

void _test_head(Deque *d){
    typeElem e;
    if(_getHead(d, &e)){
        _print(d);
    }else{
        printf("——————————失败,队为空——————————\n");
    }
}

void _test_clear(Deque *d){
    printf("————————————清空队列———————————\n");
    if(_init(d)){
        printf("\n————————————成功————————————\n\n");
    }else{
        printf("———————失败,队未初始化———————\n");
    }
}


int main(){
    Deque a;
    system("cls");
    printf("———————初始化双向队列———————\n");
    _init(&a);
    _print(&a);
    printf("初始化成功!\n\n");
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
                _test_push(&a, 0);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_push(&a, 1);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_pop(&a, 0);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_pop(&a, 1);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                _test_head(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                _test_clear(&a);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 7:
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