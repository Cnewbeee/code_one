#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000

char *mapstoi[N];
int p = 0;

struct node{
    int a, b;
}mapii[N];

int cnt[N], son[N][26], idx;
int n;
void insert(char *s){
    int p = 0;
    for(int i = 0; s[i]!= '\0'; i++){
        int u = s[i] - 'a';
        if(son[p][u] == 0)son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char *s){
    int p = 0;
    for(int i = 0; s[i]!= '\0'; i ++){
        int u = s[i] - 'a';
        if(son[p][u] == 0)return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int _cmp(const void *a, const void *b) {
    struct node *na = (struct node *)a;
    struct node *nb = (struct node *)b;
    if (na->b != nb->b)
        return nb->b - na->b;
    return strcmp(mapstoi[na->a], mapstoi[nb->a]);
}

signed main(void) {
    int i;
    char w[99];
    char tt;
    int pp = 0;
    FILE *fp = fopen("./article.txt", "rt");
    FILE *fp2 = fopen("./wordfreq.txt", "w");

    while((tt = fgetc(fp)) != EOF){
        //printf("%c\n", tt);
        if(tt >= 'A' && tt <= 'Z'){
            w[pp++] = (char)(tt + 32);
        }else if(tt >= 'a' && tt <= 'z'){
            w[pp++] = tt;
        }else{
            if(pp > 0){
                w[pp] = '\0';
                int ct = query(w);
                if(ct == 0){
                    mapstoi[p] = (char*)malloc(pp+1);
                    strcpy(mapstoi[p++], w);
                    insert(w);
                }else{
                    insert(w);
                }
                pp = 0;
            }
            //memset(c, '\0', sizeof(c));
        }
    }

    for(int i = 0; i < p; i++){
        mapii[i].a = i;
        mapii[i].b = query(mapstoi[i]);
        //printf("%s %d\n", mapstoi[i], mapii[i].b);
    }
    qsort(mapii, p, sizeof(struct node), _cmp);
    //sort(mapii, p);
    //quick_sort(mapii, 0, p-1);

    int cn = p < 100 ? p : 100;
    for(i = 0; i < cn; i++){
        printf("%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
        fprintf(fp2, "%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
    }
    while(i++ < p){
        fprintf(fp2, "%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
    }
}