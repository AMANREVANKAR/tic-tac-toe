#include <stdio.h>
char a, ar[3][3];
int b, d, count = 0, check1[100];
void setdata1(int);
void setdata2(int);
int checkdata();
int check(int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (check1[i] == x)
            return 1;
    }
}

int checkdata()
{

    if ((ar[0][0] == 'x' && ar[0][1] == 'x' && ar[0][2] == 'x') || (ar[0][0] == 'o' && ar[0][1] == 'o' && ar[0][2] == 'o'))
        return 1;
    if ((ar[1][0] == 'x' && ar[1][1] == 'x' && ar[1][2] == 'x') || (ar[1][0] == 'o' && ar[1][1] == 'o' && ar[1][2] == 'o'))
        return 1;
    if ((ar[2][0] == 'x' && ar[2][1] == 'x' && ar[2][2] == 'x') || (ar[2][0] == 'o' && ar[2][1] == 'o' && ar[2][2] == 'o'))
        return 1;
    if ((ar[0][0] == 'x' && ar[1][0] == 'x' && ar[2][0] == 'x') || (ar[0][0] == 'o' && ar[1][0] == 'o' && ar[2][0] == 'o'))
        return 1;
    if ((ar[0][1] == 'x' && ar[1][1] == 'x' && ar[2][1] == 'x') || (ar[0][1] == 'o' && ar[1][1] == 'o' && ar[2][1] == 'o'))
        return 1;
    if ((ar[0][2] == 'x' && ar[1][2] == 'x' && ar[2][2] == 'x') || (ar[0][2] == 'o' && ar[1][2] == 'o' && ar[2][2] == 'o'))
        return 1;

    if ((ar[0][0] == 'x' && ar[1][1] == 'x' && ar[2][2] == 'x') || (ar[0][0] == 'o' && ar[1][1] == 'o' && ar[2][2] == 'o'))
    {
        return 1;
    }
    if ((ar[0][2] == 'x' && ar[1][1] == 'x' && ar[2][0] == 'x') || (ar[0][2] == 'o' && ar[1][1] == 'o' && ar[2][0] == 'o'))
    {
        return 1;
    }
}
void orientation()
{

    printf(" %c   %c   %c\n", ar[0][0], ar[0][1], ar[0][2]);
    printf(" -  -  - \n");
    printf(" %c   %c   %c\n", ar[1][0], ar[1][1], ar[1][2]);
    printf(" -  -  - \n");
    printf(" %c   %c   %c\n", ar[2][0], ar[2][1], ar[2][2]);
    printf(" -  -  - \n");
}

void setdata1(int z)
{
    if (z == 1)
        ar[0][0] = 'x';
    else if (z == 2)
        ar[0][1] = 'x';
    else if (z == 3)
        ar[0][2] = 'x';
    else if (z == 4)
        ar[1][0] = 'x';
    else if (z == 5)
        ar[1][1] = 'x';
    else if (z == 6)
        ar[1][2] = 'x';
    else if (z == 7)
        ar[2][0] = 'x';
    else if (z == 8)
        ar[2][1] = 'x';
    else if (z == 9)
        ar[2][2] = 'x';
}
void setdata2(int x)
{
    if (x == 1)
        ar[0][0] = 'o';
    else if (x == 2)
        ar[0][1] = 'o';
    else if (x == 3)
        ar[0][2] = 'o';
    else if (x == 4)
        ar[1][0] = 'o';
    else if (x == 5)
        ar[1][1] = 'o';
    else if (x == 6)
        ar[1][2] = 'o';
    else if (x == 7)
        ar[2][0] = 'o';
    else if (x == 8)
        ar[2][1] = 'o';
    else if (x == 9)
        ar[2][2] = 'o';
}

void main()
{

    printf("Are you ready to play tic-tac-toe (y/n)\n");
    scanf("%c", &a);
    if (a == 'y')
    {
        printf("Orientation of places with respect to numbers are \n");
        printf(" 1  2  3\n");
        printf(" -  -  - \n");
        printf(" 4  5  6\n");
        printf(" -  -  - \n");
        printf(" 7  8  9\n");
        printf(" -  -  - \n");
        for (int i = 0; i < 5; i++)
        {
        label:
            printf("Enter the position\n");
            scanf("%d", &b);
            if (check(b) == 1)
            {
                printf("The number is already entered");
                goto label;
            }
            else
                check1[i] = b;
            setdata1(b);
            orientation();
            if (checkdata() == 1)
            {
                printf("YOU WON THE GAME\n");
                break;
            }
            if (i < 4)
            {
            label2:
                printf("Enter the position\n");
                scanf("%d", &b);
                if (check(b) == 1)
                {
                    printf("The number is already entered \n");

                    goto label2;
                }

                else
                    check1[i + 5] = b;
                setdata2(b);
                orientation();
                if (checkdata() == 1)
                {
                    printf("YOU WON THE GAME\n");
                    break;
                }
            }
        }
    }
    else
        printf("Okk");
}