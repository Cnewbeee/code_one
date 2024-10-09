#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char *c;
    int count;
}mapstoi[99999];
int p = 0;

int find(char *cc){
    for(int i = 0; i < p; i++){
        if(strcmp(mapstoi[i].c, cc) == 0 && strlen(mapstoi[i].c) == strlen(cc)){
            //printf("%s == %s\n", cc, mapstoi[i].c);
            return i;
        }
    }
    return -1;
}

int cmp(struct node a, struct node b){
    if(a.count != b.count)
        return (a.count > b.count);
    else
        return strcmp(b.c, a.c);
}

void sort(struct node *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(cmp(arr[j], arr[i]) > 0){
                struct node temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void swap(struct node a, struct node b){
    struct node temp = a;
    a = b;
    b = temp;
}

void quick_sort(struct node *f, int l, int r)
{
    if(l >= r) return ;

    struct node x = f[(l+r)>>1];
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(cmp(f[i], x) > 0);
        do j--; while(cmp(x, f[j]) > 0);
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
    FILE *fp = fopen("article.txt", "rt");
    FILE *fp2 = fopen("wordfreq.txt", "w");

    memset(w, '\0', sizeof(w));

    while((tt = fgetc(fp)) != EOF){
        //printf("%c\n", tt);
        if(tt >= 'A' && tt <= 'Z'){
            w[pp++] = (char)(tt + 32);
        }else if(tt >= 'a' && tt <= 'z'){
            w[pp++] = tt;
        }else{
            if(pp > 0 && w[0] != '\0' ){
                w[pp] = '\0';
                int ti = find(w);
                if(ti == -1){
                    mapstoi[p].c = (char*)malloc(strlen(w)+1);
                    strcpy(mapstoi[p].c, w);
                    mapstoi[p++].count = 1;
                }else{
                    mapstoi[ti].count++;
                }
                pp = 0;
            }
            //memset(c, '\0', sizeof(c));
        }
    }
    if(pp > 0 && w[0] != '\0' ){
        int ti = find(w);
        if (ti == -1) {
            mapstoi[p].c = (char*)malloc(strlen(w) + 1);
            strcpy(mapstoi[p].c, w);
            mapstoi[p++].count = 1;
        }else{
            mapstoi[ti].count++;
        }
        pp = 0;
    }

    //qsort(mapstoi, p, sizeof(struct node), cmp);
    //sort(mapstoi, p);
    quick_sort(mapstoi, 0, p-1);

    for(i = 0; i < (p < 100 ? p : 100); i++){
        printf("%s %d\n", mapstoi[i].c, mapstoi[i].count);
        fprintf(fp2, "%s %d\n", mapstoi[i].c, mapstoi[i].count);
    }
    while(i++ < p){
        fprintf(fp2, "%s %d\n", mapstoi[i].c, mapstoi[i].count);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}


