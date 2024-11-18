#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int cnt;
    struct node *left, *right;
} Node, *HuffmanTree;

void insert(HuffmanTree *root, char data, char *code, int len) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->cnt = 0;
        (*root)->left = (*root)->right = NULL;
    }

    if(len == 0) {
        (*root)->data = data;
        return;
    }

    if(code[0] == '0') {
        insert(&((*root)->left), data, code+1, len-1);
    } else {
        insert(&((*root)->right), data, code+1, len-1);
    }
}

void print_codes(HuffmanTree root, HuffmanTree p, char *code, int len) {
    if(len == -1) {
        return;
    }else{
        p->cnt++;
    }
    if(p->left == NULL && p->right == NULL) {

        printf("%c", p->data);
        if(len != 0)print_codes(root, root, code, len);
        return;
    }
    if(code[0] == '0')print_codes(root, p->left, code+1, len-1);
    else if(code[0] == '1')print_codes(root, p->right, code+1, len-1);
}

void preorder(HuffmanTree root) {
    if(root == NULL) {
        return;
    }
    
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->cnt);
}

int main() {

    HuffmanTree root = NULL;
    char data, code[100];

    int n;
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%c:", &data);
        scanf("%s", code);
        getchar();
        insert(&root, data, code, strlen(code));
    }

    char str[1000];
    FILE *fp = fopen("in.txt", "r");
    fgets(str, 1000, fp);
    fclose(fp);

    print_codes(root, root, str, strlen(str));

    printf("\n");

    preorder(root);

    return 0;
}


