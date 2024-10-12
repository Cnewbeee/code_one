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
    }else if(op == 1){//β��
        d->tail->ne = newNode;
        newNode->pr = d->tail;
        d->tail = newNode;
    }else{//ͷ��
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
    }else if(op == 0){//ͷ����
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
    printf("\n��������������������������ӡ������������������������\n");
    typeElem h, t;
    if(!_isEmpty(d)){
        _getHead(d, &h);
        _getTail(d, &t);
        printf("\n�ӳ�:%d\n����Ԫ��: %d\n��βԪ��: %d\n", _length(d), h, t);
        printf("��ֵ��Ϊ��\n");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->ne;
        }
        printf("\n");
    }else
        printf("\n��Ϊ��!\n");
    printf("\n��������������������������������������������������������\n\n");
}

void _menu(){
    printf("�������������������������˵�������������������������\n");
    printf("\t1.����ѹ��Ԫ��\n\t2.��βѹ��Ԫ��\n\t3.��������\n\t4.������β\n\t5.��ӡ\n\t6.��ն�\n\t7.�˳�\n");
    printf("������������������������ѡ�����������������\n");
}

void _test_push(Deque *d, int op){
    typeElem e;
    _print(d);
    Bool r;
    printf("��������������������ѹ��Ԫ�ء�������������������\n");
    printf("������ѹ��Ԫ��e:");
    scanf("%d", &e);
    r = _push(d, e, op);
    if(r){
        printf("�������������������������ɹ�������������������������\n");
        _print(d);
    }else{
        printf("��������������ʧ��,��δ��ʼ����������������\n");
    }
}

void _test_pop(Deque *d, int op){
    typeElem e;
    _print(d);
    printf("����������������������������������������������������\n");
    Bool r;
    r = _pop(d, &e, op);
    if(r){
        if(op == 0)
            printf("\n�������� %d �ɹ�\n", e);
        else
            printf("\n������β %d �ɹ�\n", e);
        _print(d);
    }else{
        printf("������������������Ԫ��ʧ��,��Ϊ�ա�����������\n");
    }
}

void _test_head(Deque *d){
    typeElem e;
    if(_getHead(d, &e)){
        _print(d);
    }else{
        printf("��������������������ʧ��,��Ϊ�ա�������������������\n");
    }
}

void _test_clear(Deque *d){
    printf("��������������������������ն��С���������������������\n");
    if(_init(d)){
        printf("\n�������������������������ɹ�������������������������\n\n");
    }else{
        printf("��������������ʧ��,��δ��ʼ����������������\n");
    }
}


int main(){
    Deque a;
    system("cls");
    printf("����������������ʼ��˫����С�������������\n");
    _init(&a);
    _print(&a);
    printf("��ʼ���ɹ�!\n\n");
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
                _test_push(&a, 0);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_push(&a, 1);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_pop(&a, 0);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_pop(&a, 1);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                _test_head(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                _test_clear(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 7:
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