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
    printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª´òÓ¡¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    typeElem e;
    if(!_isEmpty(s)){
        _getTop(s, &e);
        printf("\nÕ»³¤:%d\nÕ»¶¥ÔªËØ: %d\n", _length(s), e);
    }else
        printf("\nÕ»Îª¿Õ!\n");
    
    printf("\nÊýÖµÓòÎª£º\n");
    for(int i = 0; i < _length(s); i++){
        printf("%d ", s->base[i]);
    }
    printf("\n");
    printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n\n");
}

void _menu(){
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª²Ëµ¥¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    printf("\t1.Ñ¹ÈëÔªËØ\n\t2.µ¯³öÔªËØ\n\t3.È¡Õ»¶¥ÔªËØ\n\t4.Çå¿ÕÕ»\n\t5.ÍË³ö\n");
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÇëÊäÈëÑ¡Ïî¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
}

void _test_push(stack *s){
    typeElem e;
    _print(s);
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÑ¹ÈëÔªËØ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    printf("ÇëÊäÈëÑ¹ÈëÔªËØe:");
    scanf("%d", &e);
    if(_push(s, e)){
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³É¹¦¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
        _print(s);
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,Õ»Î´³õÊ¼»¯¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

void _test_pop(stack *s){
    typeElem e;
    _print(s);
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªµ¯³öÕ»¶¥¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    if(_pop(s, &e)){
        printf("\nµ¯³öÔªËØ%d³É¹¦\n", e);
        _print(s);
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªµ¯³öÔªËØÊ§°Ü,Õ»Îª¿Õ¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

void _test_top(stack *s){
    typeElem e;
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÕ»¶¥ÔªËØ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    if(_getTop(s, &e)){
        _print(s);
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,Õ»Îª¿Õ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

void _test_clear(stack *s){
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÇå¿ÕÕ»¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    _print(s);
    if(_clear(s)){
        printf("\n¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³É¹¦¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n\n");
    }else{
        printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ªÊ§°Ü,Õ»Î´³õÊ¼»¯¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    }
}

int main(){
    system("cls");
    printf("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª³õÊ¼»¯Õ»¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
    stack a;
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