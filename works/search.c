#include <stdio.h>
#include <stdlib.h>

#define MAX 18  
#define BLOCK_SIZE 3 

typedef struct {
    int index;  
    int start;  
    int length; 
} IndexItem;

int blockSearch(int mainTable[], IndexItem indexTable[], int key, int blockCount) {
    int i, j;
    for (i = 0; i < blockCount; i++) {
        if (key <= indexTable[i].index) {
            break;
        }
    }
    if (i == blockCount) {
        return -1;
    }
    for (j = 0; j < indexTable[i].length; j++) {
        if (mainTable[indexTable[i].start + j] == key) {
            return indexTable[i].start + j;
        }
    }
    return -1;
}

int main() {
    int mainTable[MAX] = {8, 14, 6, 9, 10, 22, 34, 18, 19, 31, 40, 38, 54, 66, 46, 71, 78, 68};
    IndexItem indexTable[BLOCK_SIZE] = {
        {17, 0, 6},
        {40, 6, 6},
        {78, 12, 6}
    };

    int key;
    while(1){
        printf("请输入要查找的数字：\n");
        scanf("%d", &key);
        int result = blockSearch(mainTable, indexTable, key, BLOCK_SIZE);
        if (result != -1) {
            printf("元素 %d 在主表中的位置是: %d\n", key, result);
        } else {
            printf("元素 %d 未找到\n", key);
        }
    }

    return 0;
}
