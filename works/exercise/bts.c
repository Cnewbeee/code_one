#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    int depth;
    struct tree *left;
    struct tree *right;
}tree, *treep;

void visit(treep root){
    if(root!= NULL){
        printf("%d %d\n", root->data, root->depth);
    }
}

void inorder(treep root){
    if(root!= NULL){
        inorder(root->left);
        if(root-> right == NULL && root->left == NULL)visit(root);
        inorder(root->right);
    }
}

void bst(treep *root, int data, int depth){
    if(*root == NULL){
        *root = (treep)malloc(sizeof(treep));
        (*root)->data = data;
        (*root)->depth = depth;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }else if(data < (*root)->data){
        bst(&((*root)->left), data, depth+1);
    }else{
        bst(&((*root)->right), data, depth+1);
    }
}

int main(){
    treep root = NULL;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int data;
        scanf("%d", &data);
        bst(&root, data, 1);
    }
    inorder(root);
    return 0;
}