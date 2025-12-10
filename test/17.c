#include <stdio.h>
#include <stdlib.h>

typedef struct { int a; int b; int id; } Player;

int cmp_player(const void *p1, const void *p2) {
    const Player *x = (const Player *)p1;
    const Player *y = (const Player *)p2;
    if (x->a != y->a) return (x->a < y->a) ? 1 : -1; // 体能降序
    if (x->b != y->b) return (x->b < y->b) ? 1 : -1; // 知识降序
    return (x->id > y->id) ? 1 : -1; // id 升序，保证稳定性
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *refA = (int *)malloc(sizeof(int) * n);
    int *refB = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &refA[i], &refB[i]);
    }
    int nm = n * m;
    Player *arr = (Player *)malloc(sizeof(Player) * nm);
    int idx = 0;
    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            arr[idx].a = refA[i] ^ k;
            arr[idx].b = refB[i] ^ k;
            arr[idx].id = k * n + (i + 1); // 按题意的 id 顺序
            idx++;
        }
    }
    qsort(arr, nm, sizeof(Player), cmp_player);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i].id);
    }
    free(refA);
    free(refB);
    free(arr);
    return 0;
}
