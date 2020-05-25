#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//卡牌的数量
#define card_number 54
//卡牌的结构体
typedef struct _card
{
    int id;
    char symbol;
}card;
//卡牌链表的结构体
typedef struct _card_list
{
    card *pcard;
    struct _card_list *next;
}list;
//内存池
list *card_pool = NULL;

//剩余的卡牌数
int have_card_number = 0;
//内存池中的牌数
int pool_have_card_number = 0;

//*********卡牌操作**************
//卡牌的初始化
int card_init(card* const cards, list **head);//成功返回0，失败为-1
//打印所有卡牌
int card_print(const card *cards);//成功返回0，失败为-1
//抽卡
card* draw_card(list **head);//成功返回取到的卡牌地址，失败返回NULL
//洗牌
int shuffle_card(list **head);//成功返回0，失败为-1

/*********链表操作**************/
//添加卡牌到链表
int list_add_card(list **head, card *card_address);//成功返回0，失败为-1
//删除链表中的数据
int delete_list(list *head);//成功返回0，失败为-1

/*********内存池操作*********************/
//会改变card_pool的指向,in_pool指向的链表进入内存池
int add_pool(list * const in_pool);//成功返回0，失败为-1
//删除内存池中的数据
int delete_pool();//成功返回0，失败为-1

int main(int argc, char const *argv[])
{
    card *cards = (card *)malloc(card_number * sizeof(card));
    list *head = NULL;
    card_init(cards, &head);
    //card_print(cards);
    printf("now:have card number%d\n", have_card_number);
    while (have_card_number)
    {
        card *a_card = draw_card(&head);
        if (a_card != NULL)
        {
            printf("抽出的卡是：'%c'  id: %d    have:%d\n",a_card->symbol, a_card->id, have_card_number);
        }
        
    }
    printf("have card number : %d pool have card : %d\n", have_card_number, pool_have_card_number);
    shuffle_card(&head);
    printf("have card number : %d pool have card : %d\n", have_card_number, pool_have_card_number);
    printf("waiting...\n");
    sleep(1);//等待时间变化，防止伪随机
    while(have_card_number)
    {
        card *a_card = draw_card(&head);
        if (a_card != NULL)
        {
            printf("抽出的卡是：'%c'  id: %d    have:%d\n",a_card->symbol, a_card->id, have_card_number);
        }
        
    }
    printf("have card number : %d pool have card : %d\n", have_card_number, pool_have_card_number);
    delete_list(head);
    printf("delete_list after: have card number : %d\n", have_card_number);
    printf("delete_pool before: have card number : %d\n", pool_have_card_number);
    delete_pool();
    printf("delete_pool after: have card number : %d\n", pool_have_card_number);
    free(cards);
    return 0;
}

int card_init(card* const cards, list **head)
{
    int i;
    card *pcard = cards;//可以不用pcard,下面循环内换成cards+i就行
    char card_symbol[] = {'3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K', 'A', '2'};//除jock的所有卡牌
    memset(pcard, 0, card_number * sizeof(card));
    for ( i = 0; i < card_number; i++)
    {
        pcard->id = i;
        if(i < card_number - 2)
        {
            pcard->symbol = card_symbol[i % sizeof(card_symbol)];
        }
        else if(i == card_number - 2)//'s'代表小王
        {
            pcard->symbol = 's';
        }
        else if(i == card_number - 1)//'D'代表大王
        {
            pcard->symbol = 'D';
        }
        list_add_card(head, pcard);//添加到链表
        pcard++;
        
    }

    return 0;
}

int card_print(const card * cards)
{
    int i;
    for(i = 0; i < card_number; i++)
    {
       printf("id:%d symbol:%c\t", (cards + i)->id, (cards + i)->symbol);
    }
    printf("\n");
    return 0;
}

int list_add_card(list **head, card *card_address)
{
    list *new = (list *)malloc(sizeof(list));
    static list *tail = NULL;//尾指针
    if(new == NULL)
    {
        fprintf(stderr, "malloc fail!\n");
        return -1;
    }
    memset(new, 0, sizeof(list));
    have_card_number += 1;//设定卡牌数
    new->pcard = card_address;//指向新的卡牌地址

    if(*head != NULL)
    {
        new->next =NULL;
        tail->next = new;
        tail = new;
    }
    else
    {
        new->next = NULL;
        *head = new;
        tail = new;
    }

    return 0;
}

int delete_list(list *head)
{
    while (head != NULL)
    {
        list *temp = head;
        if(head == NULL)
        {
            fprintf(stderr, "error: free NULL pointer\n!");
            return -1;
        }
        have_card_number -= 1;
        head = head->next;
        free(temp);
    }

    return 0;
}

card* draw_card(list **head)
{
    if(have_card_number <= 0)
    {
        fprintf(stderr, "draw card fail: not have card!\n");
        return NULL;
    }
    srand((unsigned)time(NULL));
    list *draw_card_list = (list *)*head;//要取出卡的链表指针
    card *draw_now_card = NULL; //要取出卡的位置
    list *previous = *head;//用于存放该成员的上一个成员的地址
    int draw_number = rand()%have_card_number;
    while (draw_number)//更具随机值取卡
    {
        if(draw_card_list == NULL)
        {
            fprintf(stderr, "draw card fail: accident NULL pointer!\n");
            return NULL;
        }
        draw_card_list = draw_card_list->next;
        draw_now_card = draw_card_list->pcard;//改变返回的卡牌
        draw_number--;
    }

    if(draw_now_card == NULL)//如果取的第一张卡,需改变头指针
    {
        draw_now_card = draw_card_list->pcard;
        *head = (*head)->next;//头指针移到下一个
        add_pool(previous);//必须改变了才进入内存池
    }
    else
    {
        while(previous->next != draw_card_list )
        {
            previous = previous->next;//获得其地址
            if(previous->next == NULL)//获得失败
                return NULL;
        }
        previous->next = draw_card_list->next;
        add_pool(draw_card_list);//必须改变了才进入内存池
        
    }
    
    have_card_number -= 1;
    //返回获得的卡牌的位置
    return draw_now_card;
}

int add_pool(list * const in_pool)
{
    if(in_pool == NULL)
    {
        fprintf(stderr, "error: NULL poniter add_pool function parameter!\n");
        return -1;
    }
    if(card_pool != NULL)
    {
        in_pool->next = card_pool;//采用头插法
        card_pool = in_pool;
    }
    else
    {
        card_pool = in_pool;
        in_pool->next = NULL;
    }
    pool_have_card_number += 1;
    return 0;
}

int delete_pool()
{
    list *temp = NULL;
    while (card_pool != NULL)
    {
        temp = card_pool;
        if(card_pool == NULL)
        {
            fprintf(stderr, "error: free NULL pointer\n!");
            return -1;
        }
        card_pool = card_pool->next;
        pool_have_card_number--;
        free(temp);
    }
    return 0;
}

int shuffle_card(list **head)
{
    list *temp = *head;//尾指针
    while (pool_have_card_number)
    {
        have_card_number++;
        pool_have_card_number--;
        if(*head != NULL)
        {
            temp->next = card_pool;
            if(card_pool == NULL)
            {
                //说明到链表最后了
                return 0;
            }
            temp = card_pool;
            card_pool = card_pool->next;
        }
        else
        {
            *head = card_pool;
            temp = card_pool;
            card_pool = card_pool->next;
        }
    }
    //意外的退出
    return -1;
}