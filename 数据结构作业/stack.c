#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000
#define typeElem int
#define Bool int
#define True 1
#define False 0
#define INCREMENT 10

typedef struct {
    typeElem *base;
    typeElem *top;
    int stackSize;
}stack;

Bool _init(stack *s){
    s->base = (typeElem*)malloc(MAXSIZE*sizeof(typeElem));
    if(s->base == NULL){
        return False;
    }
    s->top = s->base;
    s->stackSize = 0;
    return True;
}

Bool _destroy(stack *s){
    free(s->base);
    s->top = NULL;
    s->stackSize = 0;
    return True;
}

Bool _clear(stack *s){
    s->top = s->base;
    return True;
}

Bool _isEmpty(stack *s){
    if(s->top == s->base){
        return True;
    }else{
        return False;
    }
}

int _length(stack *s){
    return (s->top - s->base);    
}

Bool _getTop(stack *s, typeElem *e){
    if(_isEmpty(s) || s->base == NULL)
        return False;
    *e = *(s->top-1);
    return True;
}

Bool _push(stack *s, typeElem e){
    if(s->base == NULL){
        return False;
    }
    if(_length(s) >= s->stackSize){
        s->base = (typeElem*)realloc(s->base, s->stackSize + INCREMENT);
        s->stackSize += INCREMENT;
    }
    *s->top++ = e;

    return True;
}

Bool _pop(stack *s, typeElem *e){
    if(_isEmpty(s)){
        return False;
    }
    *e = *(--s->top);

    return True;
}

void _print(stack *s){
    printf("\n��������������������������ӡ������������������������\n");
    typeElem e;
    if(!_isEmpty(s)){
        _getTop(s, &e);
        printf("\nջ��:%d\nջ��Ԫ��: %d\n", _length(s), e);
    }else
        printf("\nջΪ��!\n");
    
    printf("\n��ֵ��Ϊ��\n");
    for(int i = 0; i < _length(s); i++){
        printf("%d ", s->base[i]);
    }
    printf("\n");
    printf("\n��������������������������������������������������������\n\n");
}

void _menu(){
    printf("�������������������������˵�������������������������\n");
    printf("\t1.ѹ��Ԫ��\n\t2.����Ԫ��\n\t3.ȡջ��Ԫ��\n\t4.���ջ\n\t5.�˳�\n");
    printf("������������������������ѡ�����������������\n");
}

void _test_push(stack *s){
    typeElem e;
    _print(s);
    printf("����������������������ѹ��Ԫ�ء���������������������\n");
    printf("������ѹ��Ԫ��e:");
    scanf("%d", &e);
    if(_push(s, e)){
        printf("�������������������������ɹ�������������������������\n");
        _print(s);
    }else{
        printf("��������������ʧ��,ջδ��ʼ����������������\n");
    }
}

void _test_pop(stack *s){
    typeElem e;
    _print(s);
    printf("��������������������������ջ������������������������\n");
    if(_pop(s, &e)){
        printf("\n����Ԫ��%d�ɹ�\n", e);
        _print(s);
    }else{
        printf("������������������Ԫ��ʧ��,ջΪ�ա�����������\n");
    }
}

void _test_top(stack *s){
    typeElem e;
    printf("����������������������ջ��Ԫ�ء���������������������\n");
    if(_getTop(s, &e)){
        _print(s);
    }else{
        printf("��������������������ʧ��,ջΪ�ա�������������������\n");
    }
}

void _test_clear(stack *s){
    printf("�����������������������������ջ����������������������\n");
    _print(s);
    if(_clear(s)){
        printf("\n�������������������������ɹ�������������������������\n\n");
    }else{
        printf("��������������ʧ��,ջδ��ʼ����������������\n");
    }
}

int main(){
    system("cls");
    printf("����������������������ʼ��ջ��������������������\n");
    stack a;
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
                _test_push(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_pop(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_top(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_clear(&a);
                printf("�����������������س�������()��������������\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
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