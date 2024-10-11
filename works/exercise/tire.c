#include<stdio.h>
#include<string.h>

const int N = 100010;

int cnt[N], son[N][26], idx;
int n;
void insert(char *s){
    int p = 0;
    for(int i = 0; i < strlen(s); i++){
        int u = s[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char *s){
    int p = 0;
    for(int i = 0; i < strlen(s); i ++){
        int u = s[i] - 'a';
        if(!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
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
                insert(w);
                pp = 0;
            }
            //memset(c, '\0', sizeof(c));
        }
    }
    if(pp > 0 && w[0] != '\0' ){
        insert(w);
        pp = 0;
    }

    //qsort(mapstoi, p, sizeof(struct node), cmp);
    //sort(mapstoi, p);
    //quick_sort(mapstoi, 0, p-1);

    
    fclose(fp);
    fclose(fp2);
    return 0;
}