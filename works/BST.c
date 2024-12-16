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

TreeNode *right_(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

TreeNode *left_(TreeNode *x)
{
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
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

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key)
        return right_(node);

    if (balance < -1 && key > node->right->key)
        return left_(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = left_(node->left);
        return right_(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = right_(node->right);
        return left_(node);
    }

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

    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0)
        return right_(root);

    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = left_(root->left);
        return right_(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return left_(root);

    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_(root->right);
        return left_(root);
    }

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

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void menu()
{
    printf("————————————BST树操作————————————\n");
    printf("\t1. 插入节点\n");
    printf("\t2. 删除节点\n");
    printf("\t3. 查找节点\n");
    printf("\t4. 中序遍历\n");
    printf("\t5. 退出\n");
    printf("—————————请输入您的选择—————————\n");
}

int main()
{
    TreeNode *root = NULL;
    int choice, key;

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入要插入的键值: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("请输入要删除的键值: ");
            scanf("%d", &key);
            root = delete_node(root, key);
            break;
        case 3:{
            printf("请输入要查找的键值: ");
            scanf("%d", &key);
            TreeNode *result = search(root, key);
            if (result != NULL)
                printf("节点 %d 找到\n", result->key);
            else
                printf("节点未找到\n");
            break;
        }
        case 4:
            printf("BST树的中序遍历结果是 \n");
            inorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("无效的选择\n");
        }
    }

    return 0;
}
