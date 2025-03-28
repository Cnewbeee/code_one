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
    printf("\n！！！！！！！！！！！！嬉咫！！！！！！！！！！！！\n");
    typeElem e;
    if(!_isEmpty(s)){
        _getTop(s, &e);
        printf("\n媚海:%d\n媚競圷殆: %d\n", _length(s), e);
    }else
        printf("\n媚葎腎!\n");
    
    printf("\n方峙囃葎��\n");
    for(int i = 0; i < _length(s); i++){
        printf("%d ", s->base[i]);
    }
    printf("\n");
    printf("\n！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
}

void _menu(){
    printf("！！！！！！！！！！！！暇汽！！！！！！！！！！！！\n");
    printf("\t1.儿秘圷殆\n\t2.起竃圷殆\n\t3.函媚競圷殆\n\t4.賠腎媚\n\t5.曜竃\n");
    printf("！！！！！！！！！萩補秘僉�遏�！！！！！！！！\n");
}

void _test_push(stack *s){
    typeElem e;
    _print(s);
    printf("！！！！！！！！！！！儿秘圷殆！！！！！！！！！！！\n");
    printf("萩補秘儿秘圷殆e:");
    scanf("%d", &e);
    if(_push(s, e)){
        printf("！！！！！！！！！！！！撹孔！！！！！！！！！！！！\n");
        _print(s);
    }else{
        printf("！！！！！！！払移,媚隆兜兵晒！！！！！！！\n");
    }
}

void _test_pop(stack *s){
    typeElem e;
    _print(s);
    printf("！！！！！！！！！！！起竃媚競！！！！！！！！！！！\n");
    if(_pop(s, &e)){
        printf("\n起竃圷殆%d撹孔\n", e);
        _print(s);
    }else{
        printf("！！！！！！！起竃圷殆払移,媚葎腎！！！！！！\n");
    }
}

void _test_top(stack *s){
    typeElem e;
    printf("！！！！！！！！！！！媚競圷殆！！！！！！！！！！！\n");
    if(_getTop(s, &e)){
        _print(s);
    }else{
        printf("！！！！！！！！！！払移,媚葎腎！！！！！！！！！！\n");
    }
}

void _test_clear(stack *s){
    printf("！！！！！！！！！！！！！賠腎媚！！！！！！！！！！！\n");
    _print(s);
    if(_clear(s)){
        printf("\n！！！！！！！！！！！！撹孔！！！！！！！！！！！！\n\n");
    }else{
        printf("！！！！！！！払移,媚隆兜兵晒！！！！！！！\n");
    }
}

int main(){
    system("cls");
    printf("！！！！！！！！！！兜兵晒媚！！！！！！！！！！\n");
    stack a;
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