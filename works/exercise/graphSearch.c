#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

int adj[MAX_VERTICES][MAX_VERTICES];

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void deleteEdge(int u, int v) {
    adj[u][v] = 0;
    adj[v][u] = 0;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    visited[v] = 1;
    printf("%d ", v);
    queue[rear++] = v;
    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adj[u][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, m, num;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    scanf("%d", &num);
    dfs(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        adj[i][num]=0;
        adj[num][i]=0;
    }
    dfs(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);
    printf("\n");
    return 0;
}