#include <stdio.h>
#include <stdlib.h>

typedef int data_tree;
typedef struct _node
{
    data_tree data;
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

/**队列的实现**/
typedef tree* data_t;
typedef struct _node_t
{
    data_t data;
    struct _node_t *next;
}LinkList;

typedef struct _queue
{
    LinkList *front;
    LinkList *rear;
}LinkQueue;


LinkQueue *creat_linkQueue(void)
{
    LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if(NULL == lq)
    {
        return NULL;
    }
    // memset(lq, 0, sizeof(LinkQueue));//可要可不用
    lq->rear = lq->front = (LinkList *)malloc(sizeof(LinkList));
    if(NULL == lq->front)
    {
        return NULL;
    }
    // lq->front->data = -1;
    lq->front->next = NULL;

    return lq;
}

int get_linkQueue_lenth(LinkQueue *lq)
{
    if(NULL == lq)
    {
        return -1;
    }
    LinkList *p = lq->front->next;
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int jugde_linkQueue_empty(LinkQueue *lq)
{
    if(NULL == lq || lq->front == NULL)
    {
        return -1;
    }
    // return (lq->front == lq->rear ? 1 : 0);//第一种方法
    return (lq->front->next == NULL ? 1 : 0);//第二种方法
}

int en_linkQueue(LinkQueue *lq, data_t data)
{
    if(NULL == lq)
    {
        return -1;
    }
    LinkList *new_listList = (LinkList *)malloc(sizeof(LinkList));
    if(new_listList == NULL)
        return -1;

    new_listList->next = NULL;
    new_listList->data = data;

    //新节点入队，即新节点添加到队尾
    lq->rear->next = new_listList;//改变队列
    lq->rear = new_listList;

    return 0;
}

int de_listQueue(LinkQueue *lq, data_t *data)
{
    if(jugde_linkQueue_empty(lq) != 0)
    {
        return -1;
    }
    LinkList *de = lq->front->next;
    lq->front->next = de->next;//如果取完lq->front->next的指为NULL
    if(data != NULL)
        *data = de->data;
    free(de);

    if(jugde_linkQueue_empty(lq) == 1)//变成了"空"队列,队列中所有成员已经取完了
        lq->rear = lq->front;//初始化,防止队尾指针指向一个已经释放的内存
    return 0;
}


int clear_listQueue(LinkQueue *lq)
{
    if(jugde_linkQueue_empty(lq) != 0)//如果是空队列
    {
        return -1;
    }
    LinkList *del;//用于释放
    while(lq->front->next)
    {
        del = lq->front->next;
        lq->front->next = del->next;//指向下一个成员地址
        free(del);
    }
    lq->rear = lq->front;//初始状态
    return 0;
}

void destroy_linkQueue(LinkQueue **lq)
{
    clear_listQueue(*lq);
    free((*lq)->front);
    (*lq)->front = NULL;
    free(*lq);
    *lq = NULL;
    return ;
}

//层次遍历
void levelOrder_print(tree *root)
{
    LinkQueue *lq = creat_linkQueue();
    if(lq == NULL)
        return ;
    en_linkQueue(lq, root);
    tree* temp = NULL;
    while(jugde_linkQueue_empty(lq) == 0)
    {
        de_listQueue(lq, &temp);
        if(temp == NULL)
            break;
        printf("%d ", temp->data);
        if(temp->lchild != NULL)
            en_linkQueue(lq, temp->lchild);
        if(temp->rchild != NULL)
            en_linkQueue(lq, temp->rchild);
    }
    destroy_linkQueue(&lq);
    printf("\n");
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

    levelOrder_print(root);
    return 0;
}
