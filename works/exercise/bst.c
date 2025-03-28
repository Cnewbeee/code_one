#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} TreeNode;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

TreeNode *new_node(int key)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

TreeNode *insert(TreeNode *node, int key)
{
    if (node == NULL)
        return new_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    return node;
}

TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *delete_node(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            TreeNode *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            TreeNode *temp = min_value_node(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

TreeNode *search(TreeNode *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int depth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lheight = depth(root->left);
    int rheight = depth(root->right);

    return (lheight > rheight) ? lheight + 1 : rheight + 1;
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("%d\n", depth(root));
    inorder(root);
    printf("\n");

    return 0;
}