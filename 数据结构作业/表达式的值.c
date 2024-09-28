#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int _getTop(stack *s, typeElem *e){
    if(_isEmpty(s) || s->base == NULL)
        return -1;
    *e = *(s->top-1);
    return *e;
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

stack num;
stack op;

void _eval(){
    int b, a, c = 0, t;
    char o;
    _pop(&num, &b);
    _pop(&num, &a);
    _pop(&op, &t);
    o = (char)t;

    if(o == '+') c = a + b;
    if(o == '-') c = a - b;
    if(o == '*') c = a * b;
    if(o == '/') c = a / b;

    _push(&num, c);
    printf("\ntest: %d %c %d = %d\n", a, o, b, c);
    //_print(&num);
}

int main(){

    _init(&num);
    _init(&op);
    char ch[MAXSIZE];
    scanf("%s", ch);
    int e;
    //printf("%s\n", ch);
    for(int i = 0; i < strlen(ch); i++){
        char t = ch[i];
        if(t >= '0' && t <= '9'){
            int x = 0, j = i;
            while(ch[j] >= '0' && ch[j] <= '9' && j < strlen(ch)){
                x = x * 10 + (ch[j++] - '0');
            }
            i = j-1;
            _push(&num, x);
        }else if(t == '(')
            _push(&op, t);
        else if(t == ')'){
            while(_getTop(&op, &e) != '(')
                _eval();
            _pop(&op, &e);
        }else{
            while(!_isEmpty(&op) && _getTop(&op, &e) != '(' && (_getTop(&op, &e) == '*' || _getTop(&op, &e) == '/' || t == '+' || t == '-'))
                _eval();
            _push(&op, t);
            //printf("\n%c\n", t);
        }
    }
    while(!_isEmpty(&op))
        _eval();

    //_print(&num);

    printf("\n%s = %d\n\n", ch, _getTop(&num, &e));

    return 0;    
}