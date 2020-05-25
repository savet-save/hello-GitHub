#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
struct STU
{
  char name[MAX_NAME_SIZE];
  int id;
  int source;
}student[100];

int receive_studnet_and_printf(struct STU *stup, int stu_num);

int main(int argc, char const *argv[])
{
  
  receive_studnet_and_printf(student, 100);
  return 0;
}

int receive_studnet_and_printf(struct STU *stup, int stu_num)
{
  if(stup == NULL || stu_num < 1)//错误参数的处理
  {
    fprintf(stderr, "error parameter: NULL pointer or stu_num less 1");
    return -1;
  }

  int ch;
  int i;
  char *temp_str = (char *)malloc(MAX_NAME_SIZE);
  struct STU * const stup_head = stup;
  //数据的接收
  while (1)
  {
    i = 0;
    printf("请输入学生名字或结束输入(#) : ");
    while ((ch = getchar()) != '\n' && ch != EOF)//获取名字
    {
      if(ch == '#' && i == 0)
      {
        stup->name[0] = '#';//结束标志
        break;
      }
      if(i >= MAX_NAME_SIZE - 2)//最后一位用于存放'\0'
      {
        i = 0;
      }
      *(temp_str + i) = ch;
      i++;
    }
    if(stup->name[0] == '#')//跳出当前循环
    {
      break;
    }
    *(temp_str + i) = '\0';
    strcpy(stup->name, temp_str);

    printf("请输入学生id : ");
    scanf("%d%*c", &(stup->id));//获得id

    printf("请输入学生分数 : ");
    scanf("%d%*c", &(stup->source));//获得分数
    
    stup++;//加1后就要判断
    if(stup - stup_head >= stu_num - 1)//防止越界,最后一个存放结束'#'
    {
      break;
    }

  }
  free(temp_str);

  //冒泡排序法
  stup = stup_head;
  struct STU temp;
  struct STU* stup2;
  for(stup2 = stup_head; (stup2+1)->name[0] != '#'; stup2++)
  {
    for(stup = stup_head; (stup+1)->name[0] != '#'; stup++)
    {
      if(stup->source > (stup+1)->source)//从小到大排序
      {
        temp = *stup;
        *stup = *(stup + 1);
        *(stup + 1) = temp;
      }
    }
  }

  stup = stup_head;//打印所有值
  while (stup->name[0] != '#')
  {
    printf("%s %d %d\n", stup->name, stup->id, stup->source);
    stup++;
  }

  return 0;
}