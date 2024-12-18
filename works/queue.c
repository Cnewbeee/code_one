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
    printf("\n！！！！！！！！！！！！嬉咫！！！！！！！！！！！！\n");
    typeElem e;
    if(!_isEmpty(q)){
        _getTop(q, &e);
        printf("\n錦海:%d\n錦遍圷殆: %d\n", _length(q), e);
        printf("\n方峙囃葎��\n");
        for(int i = q->front; i < q->rear-1; i++){
            printf("%d ", q->data[i%MAXSIZE]);
        }
    }else
        printf("\n錦葎腎!\n");

    printf("\n！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
}

void _menu(){
    printf("！！！！！！！！！！！！暇汽！！！！！！！！！！！！\n");
    printf("\t1.儿秘圷殆\n\t2.起竃圷殆\n\t3.函錦遍圷殆\n\t4.賠腎錦\n\t5.曜竃\n");
    printf("！！！！！！！！！萩補秘僉�遏�！！！！！！！！\n");
}

void _test_push(queue *q){
    typeElem e;
    _print(q);
    if(_length(q) == MAXSIZE-1){
        printf("！！！！！！！払移,錦双厮諾！！！！！！！！\n\n");
    }else{
        printf("！！！！！！！！！！儿秘圷殆！！！！！！！！！！\n");
        printf("萩補秘儿秘圷殆e:");
        scanf("%d", &e);
        if(_push(q, e)){
            printf("！！！！！！！！！！！！撹孔！！！！！！！！！！！！\n");
            _print(q);
        }else{
            printf("！！！！！！！払移,錦隆兜兵晒！！！！！！！\n");
        }
    }
        
}

void _test_pop(queue *q){
    typeElem e;
    _print(q);
    printf("！！！！！！！！！！！起竃錦遍！！！！！！！！！！！\n");
    if(_pop(q, &e)){
        printf("\n起竃圷殆%d撹孔\n", e);
        _print(q);
    }else{
        printf("！！！！！！！起竃圷殆払移,錦葎腎！！！！！！\n");
    }
}

void _test_top(queue *q){
    typeElem e;
    printf("！！！！！！！！！！！錦遍圷殆！！！！！！！！！！！\n");
    if(_getTop(q, &e)){
        _print(q);
    }else{
        printf("！！！！！！！！！！払移,錦葎腎！！！！！！！！！！\n");
    }
}

void _test_clear(queue *q){
    printf("！！！！！！！！！！！！賠腎錦双！！！！！！！！！！！\n");
    if(_clear(q)){
        printf("\n！！！！！！！！！！！！撹孔！！！！！！！！！！！！\n\n");
    }else{
        printf("！！！！！！！払移,錦隆兜兵晒！！！！！！！\n");
    }
}

int main(){
    system("cls");
    printf("！！！！！！！！！！兜兵晒錦双！！！！！！！！！\n");
    queue a;
    _init(&a);
    _print(&a);
    printf("兜兵晒撹孔!\n\n");
    printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
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
                printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_pop(&a);
                printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_top(&a);
                printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_clear(&a);
                printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                printf("！！！！！！！！！！！！曜竃！！！！！！！！！！！！\n");
                //fflush(stdin);
                return 0;
            default:
                printf("！！！！！！！！！！危列僉�遏�！！！！！！！！！\n");
                printf("！！！！！！！梓指概囚写偬()！！！！！！！\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
    }

    return 0;    

}