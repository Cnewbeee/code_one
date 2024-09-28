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

int _length(linkNode *head){//����������
    int len = 0;
    linkNode *p = head->next;
    while(p!= NULL){
        len++;
        p = p->next;
    }
    return len;
}

Bool _insert(linkNode *head, int i, elemType elem){//����ڵ�
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

Bool _delete(linkNode *head, int i, elemType *e){//ɾ���ڵ�
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

Bool _search(linkNode *head, int i, elemType *elem){//���ҽڵ�
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

void _print(linkNode *head){//��ӡ����
    printf("\n��������������������������ӡ������������������������\n");
    printf("������:%d\n��ֵ��:", _length(head));
    linkNode *p = head->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n��������������������������������������������������������\n\n");
}

void _menu(){
    printf("�������������������������˵�������������������������\n");
    printf("\t1.����Ԫ��\n\t2.ɾ��Ԫ��\n\t3.����Ԫ��\n\t4.��ӡ���Ա�\n\t5.�ϲ����Ա�\n\t6.�˳�\n");
    printf("������������������������ѡ�����������������\n");
}

void _test_insert(linkNode *L){
    int i, e;
    _print(L);
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

void _test_delete(linkNode *L){
    int i, e;
    _print(L);
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

void _test_search(linkNode *L){
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

void _test_megenu(linkNode *a, linkNode *b){
    int length_a, length_b;
    printf("�������������������ϲ����Ա�����������������\n");
    printf("��������������ʼ�����Ա�a,b��������������\n");
    a->next = NULL;
    b->next = NULL;
    _print(a);
    _print(b);
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

    _megenu(a, b);
    printf("�ϲ�������Ա�a(a+b):\n");
    _print(a);
}

int main(){
    system("cls");
    printf("������������������ʼ������������������������\n");
    linkNode head, a, b;
    head.next = NULL;
    a.next = NULL;
    b.next = NULL;
    _print(&head);
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
                _test_megenu(&a, &b);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
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