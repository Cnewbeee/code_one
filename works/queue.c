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
    printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª´òÓ¡¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    typeElem e;
    if(!_isEmpty(q)){
        _getTop(q, &e);
        printf("\n¶Ó³¤:%d\n¶ÓÊ×ÔªËØ: %d\n", _length(q), e);
        printf("\nÊýÖµÓòÎª£º\n");
        for(int i = q->front; i < q->rear-1; i++){
            printf("%d ", q->data[i%MAXSIZE]);
        }
    }else
        printf("\n¶ÓÎª¿Õ!\n");

    printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n\n");
}

void _menu(){
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª²Ëµ¥¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    printf("\t1.Ñ¹ÈëÔªËØ\n\t2.µ¯³öÔªËØ\n\t3.È¡¶ÓÊ×ÔªËØ\n\t4.Çå¿Õ¶Ó\n\t5.ÍË³ö\n");
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÇëÊäÈëÑ¡Ïî¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
}

void _test_push(queue *q){
    typeElem e;
    _print(q);
    if(_length(q) == MAXSIZE-1){
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,¶ÓÁÐÒÑÂú¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n\n");
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÑ¹ÈëÔªËØ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
        printf("ÇëÊäÈëÑ¹ÈëÔªËØe:");
        scanf("%d", &e);
        if(_push(q, e)){
            printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³É¹¦¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
            _print(q);
        }else{
            printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,¶ÓÎ´³õÊ¼»¯¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
        }
    }
        
}

void _test_pop(queue *q){
    typeElem e;
    _print(q);
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªµ¯³ö¶ÓÊ×¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    if(_pop(q, &e)){
        printf("\nµ¯³öÔªËØ%d³É¹¦\n", e);
        _print(q);
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªµ¯³öÔªËØÊ§°Ü,¶ÓÎª¿Õ¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

void _test_top(queue *q){
    typeElem e;
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¶ÓÊ×ÔªËØ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    if(_getTop(q, &e)){
        _print(q);
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,¶ÓÎª¿Õ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

void _test_clear(queue *q){
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÇå¿Õ¶ÓÁÐ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    if(_clear(q)){
        printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³É¹¦¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n\n");
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,¶ÓÎ´³õÊ¼»¯¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

int main(){
    system("cls");
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³õÊ¼»¯¶ÓÁÐ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    queue a;
    _init(&a);
    _print(&a);
    printf("³õÊ¼»¯³É¹¦!\n\n");
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
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
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_pop(&a);
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_top(&a);
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_clear(&a);
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÍË³ö¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                //fflush(stdin);
                return 0;
            default:
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª´íÎóÑ¡Ïî¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª°´»Ø³µ¼ü¼ÌÐø()¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
    }

    return 0;    

}