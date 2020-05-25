#include <stdio.h>

int print_grade(int scores);

int main(int argc, char const *argv[])
{
    printf("请输入分数 : ");
	int scores = -10;//无效输入的处理
    scanf("%d", &scores);
    print_grade(scores);
    
    return 0;
}

int print_grade(int scores)
{

    switch (scores/10)
    {
    case 10:
        printf("Perfect-your grade is A\n");
        break;
    case 9:
        printf("Excellent-your grade is A\n");
        break;
    case 8:
        printf("Very good-your grade is B\n");
        break;
    case 7:
        printf("Good-your grade is C\n");
        break;
    case 6:
        printf("OK-your grade is D\n");
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
        printf("Bad-your grade is E\n");
        break;
    default:
        fprintf(stderr, "error score\n");
        return -1;
    }

    return 0;
}

