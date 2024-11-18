#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_N 1000
#define MAX_LEN 30

typedef struct Node* PNode;
int pos = 1;
struct Node {
    char name[MAX_LEN];
    PNode parent, left, right;
    int degree;
};

PNode initNode(PNode p, char name[])
{
    if (!strcmp(name, "NULL"))
        return NULL;
    PNode n = (PNode)malloc(sizeof(struct Node));
    n->left = n->right = NULL;
    n->parent = p;
    n->degree = p ? p->degree + 1 : 1;
    strcpy(n->name, name);
    return n;
}

void getNames(char str[], char names[3][MAX_LEN])
{
    int i = 0, j = 0, k = 0;
    char c = str[i++];
    while (c != '\n' && c != '\0') {
        if (c == ' ') {
            j++;
            k = 0;
        } 
        else names[j][k++] = c;
        c = str[i++];
    }
}

PNode findNode(PNode root, char name[])
{
    if (!root) return NULL;
    else if (!strcmp(name, root->name)) return root;
    else return findNode(root->left, name) ? findNode(root->left, name) : findNode(root->right, name);
}

PNode buildTree(PNode root, char data[MAX_N][MAX_N])
{
    PNode nodes[MAX_N];
    int count = 0, i;
    nodes[count++] = root;
    for (i = 0; i < count; i++) {
        char names[3][MAX_LEN] = { '\0' };
        getNames(data[pos], names);
        if (!strcmp(nodes[i]->name, names[0])) {
            PNode left = initNode(nodes[i], names[1]), right = initNode(nodes[i], names[2]);
            nodes[i]->left = left;
            nodes[i]->right = right;
            if (left) nodes[count++] = left;
            if (right) nodes[count++] = right;
            pos++;
        }
    }
    return root;
}

void printRelation(PNode n1, PNode n2)
{
    PNode a = n1, b = n2;
    if (a->degree > b->degree)
        printf("%s %s %d", a->name, b->name, a->degree - b->degree);
    else if (a->degree < b->degree)
        printf("%s %s %d", b->name, a->name, b->degree - a->degree);
    else {
        while (strcmp(a->name, b->name)) {
            a = a->parent;
            b = b->parent;
        }
        printf("%s %s %d\n", b->name, n1->name, n1->degree - b->degree);
        printf("%s %s %d", b->name, n2->name, n2->degree - b->degree);
    }
}

int main()
{
    int n = 0;
    char data[MAX_N][MAX_N] = { '\0' }, names[3][MAX_LEN] = { '\0' }, query[2][MAX_LEN];
    FILE* file = fopen("in.txt", "r");
    while (!feof(file))
        fgets(data[n++], 3 * MAX_LEN, file);
    fclose(file);
    getNames(data[1], names);
    PNode root = initNode(NULL, names[0]);
    buildTree(root, data);
    scanf("%s %s", query[0], query[1]);
    PNode node1 = findNode(root, query[0]), node2 = findNode(root, query[1]);
    printRelation(node1, node2);
    return 0;
}
