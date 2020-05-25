#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student 
{
    unsigned int id; 
    char name[20];
    struct Student *next;
}student;

int add_studnet(student **stp);//创建链表
int print_student_list(student *head);//打印整个链表
int free_student_list(student *head);//删除内存中的整个链表
int del_student(student **head, unsigned int n);//删除内存中链表中的某个成员(根据序列)
int search_student_list(student *head, unsigned int sid);//查找成员并打印(根据成员属性id)
int insert_student_list(student **head, unsigned int n);//插入成员（根据序列,在此序列成员之后）
int updata_student_list(student *head, unsigned int n);//修改成员属性（根据序列）

unsigned int stid = 0;

int main(int argc, char const *argv[])
{
    student *stp = NULL;
    while(stid < 4)
    {
        if(add_studnet(&stp) < 0)
            break;
    }
    print_student_list(stp);
    updata_student_list(stp, 1);
    del_student(&stp, 3);
    add_studnet(&stp);
    print_student_list(stp);
    free_student_list(stp);
    return 0;
}

int add_studnet(student **stp)
{
    student *new_stu = (student *)malloc(sizeof(student));
    if(new_stu == NULL)
    {
        fprintf(stderr,"malloc fail!\n");
        return -1;
    }
    memset(new_stu, 0, sizeof(student));
    
    stid = stid +1;
    new_stu->id = stid;
    strcpy(new_stu->name, "zhangsan");

    student *tail = *stp;//用于尾插法
    
    if(*stp != NULL)
    {
        /*
        //头插法
        new_stu->next = *stp;
        *stp = new_stu;
        */

        //尾插法
        while(tail->next)tail = tail->next;//找到尾巴
        tail->next = new_stu;
        new_stu->next = NULL;
        
    }
    else
    {
        new_stu->next = NULL;
        *stp = new_stu;
    }
    
    return 0;
}

int print_student_list(student *head)
{
    while(head != NULL)
    {
        if(head->name[0] == 0)
        {
            fprintf(stderr,"error access in head->name");
            return -1;
        }
        printf("id:%d name:%s\n",head->id, head->name);
        head = head->next;
    }
    return 0;
}

int free_student_list(student *head)
{
    while(head !=NULL)
    {
        student *temp = head;
        head = head->next;
        free(temp);
    }
    printf("free student_list succes!\n");
    return 0;
}

int del_student(student **head, unsigned int n)
{
    student *del_stu = *head;
    while(n > 0)//判断删除第多少个成员
    {
        del_stu = del_stu->next;
        if(del_stu == NULL)
            return -1;
        n--;
    }
    if((*head)->next == NULL)//说明链表只有一个成员
    {
        free(*head);
        *head = NULL;//防止成为野指针
    }
    else//链表有多个成员
    {
        //判断删除的是不是第一个成员
        if(del_stu != *head)//若不是
        {
            student *previous = *head;//用于存放该成员的上一个成员的地址
            while(previous->next != del_stu )
            {
                previous = previous->next;//获得其地址
                if(previous->next == NULL)//获得失败
                    return -1;
            }
            previous->next = del_stu->next;
            free(del_stu);
        
        }
        else//若是第一个成员
        {
            student *temp = del_stu->next;
            free(del_stu);//释放该成员占用的内存
            *head = temp;//更改头指针位置
        }
    }
    
    return 0;
}

int search_student_list(student *head, unsigned int sid)
{
    while(head->id != sid )  
    {
        head = head->next;
        if(head == NULL)
        {
            printf("Not find!\n");
            return -1;
        }
    }
    printf("id:%d name:%s\n",head->id, head->name);
    return 0;
}

int insert_student_list(student **head, unsigned int n)
{
    student *ins_stu = *head;
    while(n > 0)//判断插入第多少个成员
    {
        ins_stu = ins_stu->next;
        if(ins_stu == NULL)
            return -1;
        n--;
    }
    student *temp = ins_stu->next;//保存下一个成员
    ins_stu->next = (student *)malloc(sizeof(student));//指向新的成员
    stid = stid +1;
    ins_stu->next->id = stid;
    strcpy(ins_stu->next->name, "zhangsan");
    ins_stu->next->next = temp;//新创建的成员指向保存的成员

    return 0;
}

int updata_student_list(student *head, unsigned int n)
{
    student *upd_stu = head;
    while(n > 0)//判断插入第多少个成员
    {
        upd_stu = upd_stu->next;
        if(upd_stu == NULL)
            return -1;
        n--;
    }
    //更新数据
    upd_stu->id = 1990;
    strcpy(upd_stu->name, "wanger");
    return 0;
}