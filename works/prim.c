#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10
#define MAX_ 7
#define typeElem char
#define Bool int
#define True 1
#define False 0
#define INF 0x3f3f3f3f

typedef struct{
    int u, v, w;
}edge;

int g[MAXSIZE][MAXSIZE];
char name[MAXSIZE];
int dist[MAXSIZE], pre[MAXSIZE];
int st[MAXSIZE], num = 0, idx = 0, len = 0;
edge ans[MAXSIZE];

int prim(){
    
    int res = 0, tt = 0;
    //dist[0] = 0;
    
    for(int i = 0; i < num; i++){
        int t = -1;
        for(int j = 1; j <= num; j++){
            if(!st[j] && t == -1)t = j;
            else if(!st[j] && dist[j] < dist[t])t = j;
        }
        //if(i && dist[t] == INF)return INF;
        st[t] = 1;
        if(i)res += dist[t],ans[len].u = pre[t], ans[len].v = t, ans[len++].w = dist[t];
        //printf("-%d-\n", res);
        
        for(int j = 1; j <= num; j++){
            //printf("t=%d j=%d -- g[t][j]=%d\n", t, j, g[t][j]);
            if(dist[j] > g[t][j]){
                dist[j] = g[t][j];
                pre[j] = t;
            }
        }
    }
    
    return res;
}

int main(){
    printf("������ͼ�Ľڵ�����\n");
    scanf("%d", &num);

    memset(g, INF, sizeof(g));
    memset(dist, INF, sizeof(dist));
    // for(int i = 1; i <= num; i++){
    //     printf("dist[%d]=%d\n", i, dist[i]);
    //     for(int j = 1; j <= num; j++){
    //         printf("g[%d][%d]=%d ", i, j, g[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i = 0; i < num; i++){
        int a, b;
        int w = 0;
        printf("������ߣ�(�ڵ�1 �ڵ�2 Ȩֵ)\n");
        scanf("%d%d%d", &a, &b, &w);
        //getchar();
        //scanf("%c", &b);
        //printf("%d %d\n", w, g[a][b]);
        g[a][b] = g[b][a] = (w < g[a][b] ? w : g[a][b]);
        //printf("%d--%d=%d\n", a, b, g[b][a]);
        printf("�ɹ���ӱߣ�%d--%d=%d\n", a, b, g[a][b]);
    }

    int s = prim();
    if(s == INF)printf("impossible\n");
    else printf("��С��������Ȩֵ��%d \n", s);
    printf("��С�������ıߣ�\n");
    for(int i = 0; i < len; i++){
        printf("%d--%d=%d \n", ans[i].u, ans[i].v, ans[i].w);
    }

    return 0;
}