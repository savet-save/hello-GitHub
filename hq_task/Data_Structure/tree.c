#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node
{
    data_t data;
    struct _node *lchild;
    struct _node *rchild;
}tree;

//i:序号起点，每次加一
//n：序号上限
tree *crearTree(int i, int n)
{
    tree *root = (tree *)malloc(sizeof(tree));
    if(NULL == root)
        return NULL;
    root->data = i;

    if(i * 2 <= n)
        root->lchild = crearTree(i * 2, n);
    else
        root->lchild = NULL;
    
    if(i * 2 + 1 <= n)
        root->rchild = crearTree(i * 2 + 1, n);
    else
        root->rchild = NULL;
    
    return root;
}

//前序遍历
void perOrder_print(tree *root)
{
    if(root == NULL)
        return ;
    printf("%d ", root->data);
    perOrder_print(root->lchild);
    perOrder_print(root->rchild);
    return ;
}

//中序遍历
void minOrder_print(tree *root)
{
    if(root == NULL)
        return ;
    minOrder_print(root->lchild);
    printf("%d ", root->data);
    minOrder_print(root->rchild);
    return ;
}

//后序遍历
void reaOrder_print(tree *root)
{
    if(root == NULL)
        return ;
    reaOrder_print(root->lchild);
    reaOrder_print(root->rchild);
    printf("%d ", root->data);
    return ;
}

int main(int argc, char const *argv[])
{
    tree* root = crearTree(1, 12);
    perOrder_print(root);
    printf("\n");

    minOrder_print(root);
    printf("\n");

    reaOrder_print(root);
    printf("\n");

    return 0;
}
