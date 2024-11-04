#include <stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
#define typeElem int
#define Bool int
#define True 1
#define False 0

typedef struct {
    int rear;
    int front;
    typeElem *data;
}queue;

Bool _init(queue *q){
    q->data = (typeElem*)malloc(MAXSIZE*sizeof(typeElem));
    if(q->data == NULL){
        return False;
    }
    q->front = 0;
    q->rear = 1;
    return True;
}

Bool _destroy(queue *q){
    free(q->data);
    q->front = q->rear = 0;
    return True;
}

Bool _clear(queue *q){
    q->front = 0;
    q->rear = 1;
    return True;
}

Bool _isEmpty(queue *q){
    if((q->rear - q->front - 1)%MAXSIZE == 0){
        return True;
    }else{
        return False;
    }
}

int _length(queue *q){
    return (q->rear - q->front - 1);    
}

Bool _getTop(queue *q, typeElem *e){
    if(_isEmpty(q) || q->data == NULL)
        return False;
    *e = q->data[(q->front)%MAXSIZE];
    return True;
}

Bool _push(queue *q, typeElem e){
    if(q->data == NULL || _length(q) == MAXSIZE){
        return False;
    }
    q->data[((q->rear++)-1)%MAXSIZE] = e;

    return True;
}

Bool _pop(queue *q, typeElem *e){
    if(_isEmpty(q)){
        return False;
    }
    *e = q->data[(q->front++)%MAXSIZE];

    return True;
}

void _print(queue *q){
    printf("\n��������������������������ӡ������������������������\n");
    typeElem e;
    if(!_isEmpty(q)){
        _getTop(q, &e);
        printf("\n�ӳ�:%d\n����Ԫ��: %d\n", _length(q), e);
        printf("\n��ֵ��Ϊ��\n");
        for(int i = q->front; i < q->rear-1; i++){
            printf("%d ", q->data[i%MAXSIZE]);
        }
    }else
        printf("\n��Ϊ��!\n");

    printf("\n��������������������������������������������������������\n\n");
}

void _menu(){
    printf("�������������������������˵�������������������������\n");
    printf("\t1.ѹ��Ԫ��\n\t2.����Ԫ��\n\t3.ȡ����Ԫ��\n\t4.��ն�\n\t5.�˳�\n");
    printf("������������������������ѡ�����������������\n");
}

void _test_push(queue *q){
    typeElem e;
    _print(q);
    if(_length(q) == MAXSIZE-1){
        printf("��������������ʧ��,������������������������\n\n");
    }else{
        printf("��������������������ѹ��Ԫ�ء�������������������\n");
        printf("������ѹ��Ԫ��e:");
        scanf("%d", &e);
        if(_push(q, e)){
            printf("�������������������������ɹ�������������������������\n");
            _print(q);
        }else{
            printf("��������������ʧ��,��δ��ʼ����������������\n");
        }
    }
        
}

void _test_pop(queue *q){
    typeElem e;
    _print(q);
    printf("�����������������������������ס���������������������\n");
    if(_pop(q, &e)){
        printf("\n����Ԫ��%d�ɹ�\n", e);
        _print(q);
    }else{
        printf("������������������Ԫ��ʧ��,��Ϊ�ա�����������\n");
    }
}

void _test_top(queue *q){
    typeElem e;
    printf("��������������������������Ԫ�ء���������������������\n");
    if(_getTop(q, &e)){
        _print(q);
    }else{
        printf("��������������������ʧ��,��Ϊ�ա�������������������\n");
    }
}

void _test_clear(queue *q){
    printf("��������������������������ն��С���������������������\n");
    if(_clear(q)){
        printf("\n�������������������������ɹ�������������������������\n\n");
    }else{
        printf("��������������ʧ��,��δ��ʼ����������������\n");
    }
}

int main(){
    system("cls");
    printf("����������������������ʼ�����С�����������������\n");
    queue a;
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