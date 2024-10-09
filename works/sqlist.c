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
    printf("\n��������������������������ӡ������������������������\n");
    printf("���Ա���:%d\n��ֵ��:", L->length);
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->arr[i]);    
    }
    printf("\n��������������������������������������������������������\n\n");
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
    printf("�������������������������˵�������������������������\n");
    printf("\t1.����Ԫ��\n\t2.ɾ��Ԫ��\n\t3.����Ԫ��\n\t4.��ӡ���Ա�\n\t5.�ϲ����Ա�\n\t6.�˳�\n");
    printf("������������������������ѡ�����������������\n");
}

void _test_insert(sqlist *L){
    int i, e;
    printf("����������������������Ԫ�ز��롪��������������������\n");
    while(1){
        printf("���������λ��i:");
        scanf("%d", &i);
        printf("���������Ԫ��e:");
        scanf("%d", &e);
        if(_insert(L, i, e)){
            printf("�������������������������ɹ�������������������������\n");
            _print(L);
            break;
        }else{
            printf("������������������ʧ��,�����ԡ�����������������\n");
        }
    }
}

void _test_delete(sqlist *L){
    int i, e;
    printf("����������������������Ԫ��ɾ������������������������\n");
    while(1){
        printf("������ɾ��λ��i:");
        scanf("%d", &i);
        if(_delete(L, i, &e)){
            printf("ɾ��Ԫ��%d�ɹ�\n", e);
            _print(L);
            break;
        }else{
            printf("ɾ��Ԫ��ʧ��,������\n");
        }
    }
}

void _test_search(sqlist *L){
    int i, e;
    printf("����������������������Ԫ�ز��ҡ���������������������\n");
    while(1){
        printf("���������λ��i:");
        scanf("%d", &i);
        if(_search(L, i, &e)){
            printf("Ԫ��%d����\n", e);
            break;
        }else{
            printf("Ԫ�ز�����,������\n");
        }
    }
}

void _test_megenu(sqlist *a, sqlist *b, sqlist *c){
    int length_a, length_b;
    printf("�������������������ϲ����Ա�����������������\n");
    printf("��������������ʼ�����Ա�a,b,c����������\n");
    _init(a);
    _init(b);
    _init(c);
    _print(a);
    _print(b);
    _print(c);
    printf("�������������������������ɹ�������������������������\n");

    printf("���������Ա�a�ĳ���:\n");
    scanf("%d", &length_a);
    printf("���������Ա�a��Ԫ��(����):\n");
    for(int i = 0; i < length_a; i++){
        int e;
        printf("�������%d��Ԫ��:\n", i+1);
        scanf("%d", &e);
        _insert(a, i+1, e);
    }
    _print(a);
    printf("���������Ա�b�ĳ���:\n");
    scanf("%d", &length_b);
    printf("���������Ա�b��Ԫ��(����):\n");
    for(int i = 0; i < length_b; i++){
        int e;
        printf("�������%d��Ԫ��:\n", i+1);
        scanf("%d", &e);
        _insert(b, i+1, e);
    }
    _print(b);

    _megenu(a, b, c);
    printf("�ϲ�������Ա�c:\n");
    _print(c);
}

int main(){
    system("cls");
    sqlist a, b, c;
    printf("������������������ʼ�����Ա���������������\n");
    _init(&a);
    _init(&b);
    _init(&c);
    _print(&a);
    printf("�������������������������ɹ�������������������������\n\n");
    printf("�����������������س�������()��������������\n");
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
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_delete(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_search(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _print(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                _test_megenu(&a, &b, &c);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                _destroy(&a);
                _destroy(&b);
                _destroy(&c);
                printf("�������������������������˳�������������������������\n");
                //fflush(stdin);
                return 0;
            default:
                printf("������������������������ѡ�������������������\n");
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
    }

    return 0;    
}