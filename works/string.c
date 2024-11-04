#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10000
#define typeElem char
#define Bool int
#define True 1
#define False 0

typedef struct{
    typeElem data[MAXSIZE];
    int length;
}String;

String list[100];
int list_length = 0;

Bool _strAssign(String *s, char *str){
    int i = 0;
    while(str[i]!= '\0'){
        if(s->length >= MAXSIZE){
            return False;
        }
        s->data[s->length] = str[i];
        s->length++;
        s->data[s->length] = '\0';
        i++;
    }
    return True;
}

Bool _strCopy(String *a, String *b){
    if(a->length >= MAXSIZE || b->length >= MAXSIZE){
        return False;
    }
    for(int i = 0; i < b->length; i++){
        a->data[i] = b->data[i];
    }
    a->length = b->length;
    return True;
}

int _strCompare(String a, String b){
    if(a.length != b.length){
        return a.length - b.length;
    }
    for(int i = 0; i < a.length; i++){
        if(a.data[i] != b.data[i]){
            return a.data[i] - b.data[i];
        }
    }
    return 0;
}

int _strLength(String *s){
    return s->length;
}

Bool _concat(String a, String b, String *c){
    if(a.length + b.length >= MAXSIZE){
        return False;
    }
    for(int i = 0; i < a.length; i++){
        c->data[i] = a.data[i];
    }
    for(int i = 0; i < b.length; i++){
        c->data[a.length + i] = b.data[i];
    }
    c->length = a.length + b.length;
    c->data[c->length] = '\0';
    return True;
}

Bool _subString(String s, int start, int end, String *sub){
    if(start < 0 || end > s.length || start > end){
        return False;
    }
    if(end - start + 1 >= MAXSIZE){
        return False;
    }
    for(int i = start; i <= end; i++){
        sub->data[i - start] = s.data[i];
    }
    sub->length = end - start + 1;
    sub->data[sub->length] = '\0';
    return True;
}

void _print(String *s){
    printf("\n————————————打印————————————\n");
    printf("\n字符串长度: %d\n\n", s->length);
    for(int i = 0; i < s->length; i++){
        printf("%c", s->data[i]);    
    }
    printf("\n\n————————————————————————————\n\n");
}

void _printall(){
    printf("\n————————————打印————————————\n");
    for(int i = 0; i < list_length; i++){
        printf("\n字符串%d:\n", i);
        printf("%s\n", list[i].data);
    }
    printf("\n————————————————————————————\n\n");
}

void _kmp(){
    String p, s, s0;
    int a, b, n, m, ne[MAXSIZE];
    memset(ne, 0, sizeof(ne));

    _printall();
    printf("\n————————————KMP————————————\n");

    printf("\n请输入两个字符串的编号：");
    scanf("%d %d", &a, &b);
    if(a < 0 || a >= list_length || b < 0 || b >= list_length){
        printf("\n输入的编号超出范围\n");
        return;
    }
    _strAssign(&s0, " ");
    _concat(s0, list[b], &p);
    _concat(s0, list[a], &s);
    n = p.length-1;
    m = s.length-1;

    for(int i = 2, j = 0; i <= n; i ++){
        while(j && p.data[i] != p.data[j+1]) j = ne[j];
        if(p.data[i] == p.data[j+1]) j++;
        ne[i] = j;
    }
    int r = 0;
    for(int i = 1, j = 0; i <= m; i ++){
        while(j && s.data[i] != p.data[j+1]) j = ne[j];
        if(s.data[i] == p.data[j+1]) j++;
        if(j == n){
            printf("\n%s 在%s 中第%d个位置\n", p.data, s.data, i - n + 1);
            r = 1;
            j = ne[j];
        }
    }
    if(r == 0) 
        printf("\n%s 不在%s 中\n", p.data, s.data);
    
}


void _menu(){
    printf("————————————菜单————————————\n");
    printf("\t1.创建字符串\n\t2.比较字符串\n\t3.打印字符串\n\t4.连接字符串\n\t5.截取子串\n\t6.KMP\n\t7.退出\n");
    printf("—————————请输入选项—————————\n");
}

Bool _test_strAssign(){
    String s;
    s.length = 0;
    _printall();
    char str[MAXSIZE];
    printf("请输入字符串：");
    scanf("%s", str);
    if(_strAssign(&s, str) == False){
        printf("字符串数量超过最大值\n");
        return False;
    }
    list[list_length++] = s;

    printf("字符串%d创建成功\n", list_length - 1);

    printf("\n————————————成功————————————\n");

    _print(&s);

    return True;
}

void _test_strCompare(){
    int a, b;
    _printall();
    printf("\n请输入两个字符串的编号：");
    scanf("%d %d", &a, &b);
    if(a < 0 || a >= list_length || b < 0 || b >= list_length){
        printf("\n输入的编号超出范围\n");
        return;
    }
    String s1, s2;
    s1 = list[a];
    s2 = list[b];
    int result = _strCompare(s1, s2);
    if(result == 0){
        printf("\n字符串相等\n");
    }else if(result > 0){
        printf("\n%s大于%s\n", s1.data, s2.data);
        printf("\n字符串%d大于字符串%d\n", a, b);
    }else{
        printf("\n%s小于%s\n", s1.data, s2.data);
        printf("\n字符串%d小于字符串%d\n", a, b);
    }
}

Bool _test_print(){
    int a;
    printf("\n请输入字符串的编号：");
    scanf("%d", &a);
    if(a < 0 || a >= list_length){
        printf("\n输入的编号超出范围\n");
        return False;
    }
    _print(&list[a]);
    return True;
}

Bool _test_concat(){
    int a, b;
    _printall();
    printf("请输入两个字符串的编号：");
    scanf("%d %d", &a, &b);
    if(a < 0 || a >= list_length || b < 0 || b >= list_length){
        printf("输入的编号超出范围\n");
        return False;
    }
    String s1, s2, s3;
    s1 = list[a];
    s2 = list[b];
    if(_concat(s1, s2, &s3) == False){
        printf("字符串数量超过最大值\n");
        return False;
    }
    list[list_length++] = s3;
    printf("字符串%d连接成功\n", list_length - 1);
    printf("\n————————————成功————————————\n");
    _print(&s3);
    return True;
}

Bool _test_subString(){
    int a;
    _printall();
    printf("\n请输入字符串的编号：\n");
    scanf("%d", &a);

    if(a < 0 || a >= list_length){
        printf("\n输入的编号超出范围\n");
        return False;
    }
    String s1, s2;
    int start, end;
    printf("\n请输入子串的起始位置和结束位置：\n");
    scanf("%d %d", &start, &end);
    start--, end--;
    if(start < 0 || end > list[a].length){
        printf("\n输入的位置超出范围\n");
        return False;
    }
    if(_subString(list[a], start, end, &s2) == False){
        printf("\n字符串数量超过最大值\n");
        return False;
    }
    list[list_length++] = s2;
    printf("子串%d截取成功\n", list_length - 1);
    printf("\n————————————成功—\n");
    _print(&s2);
    return True;
}

int main(){
    int choice;
    while(True){
        _menu();
        printf("请输入选项：");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                _test_strAssign();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                _test_strCompare();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                _test_print();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 4:
                _test_concat();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 5:
                _test_subString();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 6:
                _kmp();
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 7:
                printf("————————————退出————————————\n");
                return 0;
            default:
                printf("——————————错误选项——————————\n");
                printf("———————按回车键继续()———————\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }  
    }
    return 0;
}