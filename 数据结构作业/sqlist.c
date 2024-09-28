#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
#define typeElem int
#define Bool int
#define True 1;
#define False 0;

typedef struct{
    typeElem *arr;
    int length;
}sqlist;

Bool _init(sqlist *L){
    L->arr = (typeElem*)malloc(MAXSIZE*sizeof(typeElem));
    if(L->arr == NULL){
        return False;
    }
    L->length = 0;
    return True;
}

Bool _destroy(sqlist *L){
    free(L->arr);
    L->length = 0;
    return True;
}

Bool _insert(sqlist *L, int i, typeElem e){
    if(i < 1 || i > L->length+1){
        return False;
    }
    if(L->length == MAXSIZE){
        return False;
    }
    for(int j = L->length; j >= i; j--){
        L->arr[j] = L->arr[j-1];
    }
    L->arr[i-1] = e;
    L->length++;
    return True;
}

Bool _delete(sqlist *L, int i, typeElem *e){
    if(i < 1 || i > L->length || i >= MAXSIZE){
        return False;
    }
    *e = L->arr[i-1];
    for(int j = i; j < L->length; j++){
        L->arr[j-1] = L->arr[j];
    }
    L->length--;
    return True;
}

Bool _search(sqlist *L, int i, typeElem *e){
    if(i < 1 || i > L->length || i >= MAXSIZE){
        return False;
    }
    *e = L->arr[i-1];
    return True;
}

void _print(sqlist *L){
    printf("\n————————————打印————————————\n");
    printf("线性表长度:%d\n数值域:", L->length);
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->arr[i]);    
    }
    printf("\n————————————————————————————\n\n");
}

void _megenu(sqlist *a, sqlist *b, sqlist *c){
    int i = 0, j = 0, k = 0;
    while(i < a->length && j < b->length){
        if(a->arr[i] < b->arr[j]){
            c->arr[k] = a->arr[i];
            i++;
        }else{
            c->arr[k] = b->arr[j];
            j++;
        }
        k++;
    }
    while(i < a->length){
        c->arr[k] = a->arr[i];
        i++;
        k++;
    }
    while(j < b->length){
        c->arr[k] = b->arr[j];
        j++;
        k++;
    }
    c->length = k;
}
void _menu(){
    printf("————————————菜单————————————\n");
    printf("\t1.插入元素\n\t2.删除元素\n\t3.查找元素\n\t4.打印线性表\n\t5.合并线性表\n\t6.退出\n");
    printf("—————————请输入选项—————————\n");
}

void _test_insert(sqlist *L){
    int i, e;
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

void _test_delete(sqlist *L){
    int i, e;
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

void _test_search(sqlist *L){
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

void _test_megenu(sqlist *a, sqlist *b, sqlist *c){
    int length_a, length_b;
    printf("—————————合并线性表—————————\n");
    printf("——————初始化线性表a,b,c—————\n");
    _init(a);
    _init(b);
    _init(c);
    _print(a);
    _print(b);
    _print(c);
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

    _megenu(a, b, c);
    printf("合并后的线性表c:\n");
    _print(c);
}

int main(){
    system("cls");
    sqlist a, b, c;
    printf("————————初始化线性表————————\n");
    _init(&a);
    _init(&b);
    _init(&c);
    _print(&a);
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
                _test_megenu(&a, &b, &c);
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                _destroy(&a);
                _destroy(&b);
                _destroy(&c);
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