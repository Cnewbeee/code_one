#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000

char *mapstoi[99999];
int p = 0;

struct node{
    int a, b;
}mapii[99999];


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


int cmp(struct node a, struct node b){
    if(a.b != b.b)
        if(a.b < b.b)
            return 1;
        else
            return 0;
    else
        return strcmp(mapstoi[a.a], mapstoi[b.a]);
}

int _cmp(const void *a, const void *b) {
    struct node *na = (struct node *)a;
    struct node *nb = (struct node *)b;
    if (na->b != nb->b)
        return nb->b - na->b; // ½µÐòÅÅÁÐ
    return strcmp(mapstoi[na->a], mapstoi[nb->a]);
}

void quick_sort(struct node *f, int l, int r)
{
    if(l >= r) return ;

    struct node x = f[(l+r)>>1];
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(cmp(x, f[i]) > 0);
        do j--; while(cmp(f[j], x) > 0);
        if(i < j) {
            struct node temp = f[i];
            f[i] = f[j];
            f[j] = temp;
        }
    }

    quick_sort(f, l, j);
    quick_sort(f, j+1, r);
}

int main() {
    int i = 1;
    char w[9999];
    char tt;
    int pp = 0;
    FILE *fp = fopen("./article.txt", "rt");
    FILE *fp2 = fopen("./wordfreq.txt", "w");

    memset(mapii, 0, sizeof(mapii));

    while((tt = fgetc(fp)) != EOF){
        //printf("%c\n", tt);
        if(tt >= 'A' && tt <= 'Z'){
            w[pp++] = (char)(tt + 32);
        }else if(tt >= 'a' && tt <= 'z'){
            w[pp++] = tt;
        }else{
            if(pp > 0 && w[0] != '\0' ){
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
    if(pp > 0 && w[0] != '\0' ){
        int ti = query(w);
        if (ti == 0) {
            mapstoi[p] = (char*)malloc(pp + 1);
            strcpy(mapstoi[p], w);
            insert(w);
        }else{
            insert(w);
        }
        pp = 0;
    }
    //printf("p = %d\n", p);

    for(int i = 0; i < p; i++){
        mapii[i].a = i;
        mapii[i].b = query(mapstoi[i]);
        //printf("%s %d\n", mapstoi[i], mapii[i].b);
    }
    qsort(mapii, p, sizeof(struct node), _cmp);
    //sort(mapii, p);
    //quick_sort(mapii, 0, p-1);

    for(i = 0; i < (p < 100 ? p : 100); i++){
        printf("%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
        fprintf(fp2, "%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
    }
    while(i++ < p){
        fprintf(fp2, "%s %d\n", mapstoi[mapii[i].a], mapii[i].b);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}


