#include<stdio.h>
#include <windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int turn ,flag ;
 FILE *scr;
int player,comp;
int sump=0,sumc=0;
int board[10];
void menu();
void go(int n);
void GAME_START();
int DRAW();
void F();
void PLAYER_FIRST();
void put_X_O(char ch,int pos);
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
int pl,cp;
    scr=fopen("score112.text","w");

   for(int i=1;i<=3;i++){
    system("cls");
    for(int j=0;j<10;j++)
   board[j]=2;
turn=1;
flag=0;
    menu();

    getch();}
    fclose(scr);

  scr=fopen("score112.text","r");
  printf("\n%-10s%-20s\n","User","Computer");


for(int i=1;i<=3;i++){
    fscanf(scr,"%d%d",&pl,&cp);
     printf("\n%-10d%-20d\n",pl,cp);}
     printf("\n computer = %d    player = %d ",sumc,sump);
   if(sump>sumc)
   {
       printf("\nYOU ARE THE WINNER :D ");
   }
   else if(sumc==sump)
   {
       printf("\nDRAW GAME :'( ");
   }
   else {
      printf("\nCOMPUTER IS THE WINNER :D ");
   }

    return 0;
}
void menu()
{
    int choice;

    system("cls");
    printf("%51s","Welcome to TIC TAC TOE");
    printf("\n   START GAME");
    printf("\n");
    printf("\nCHOOSE YOUR OPTION");
    printf("\n=>");
    printf("\n1 : Play with X (Enter : 1) ");
    printf("\n2 : Play with O (Enter : 2)");
    printf("\n3 : Exit");
    printf("\nEnter your choice:>");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        PLAYER_FIRST();
        break;
    case 2:
        player = 0;
        comp = 1;
        GAME_START();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }
    return;

}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)
    {
        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+1] == 2)
                return i+1;
            if(board[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+3] == 2)
                return i+3;
            if(board[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
        if(board[1] == 2)
            return 1;
        if(board[5] == 2)
            return 5;
        if(board[9] == 2)
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        if(board[3] == 2)
            return 3;
        if(board[5] == 2)
            return 5;
        if(board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void PLAYER_FIRST()
{
    int pos;
    int count=0;


    if(DRAW()==1)
        return ;
    F();
    gotoxy(30,18);
    printf("YOUR TURN :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        PLAYER_FIRST();

    if(pos == posswin(player))
    {
        go(pos);
        F();
        gotoxy(30,20);

        printf("YOU WINS !!");
        printf("GAME OVER");

        fprintf(scr,"%d %d\n",3,0);

         sump+=3;
        count++;


     return ;
        //exit(0);
    }
    go(pos);
    F();
    if(turn==9)
        return ;
    GAME_START();
}

void GAME_START()
{

    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    F();

    if(flag)
    {
        gotoxy(30,20);

        printf("COMPUTER WINS !!");
        printf("GAME OVER");

        fprintf(scr,"%d %d\n",0,3);
         sumc+=3;


        return ;
        //exit(0);
    }
    else
    {
       // if(turn==9)
           // return ;
        PLAYER_FIRST();
    }
}

int DRAW()
{
    if(turn > 9)
    {
        gotoxy(30,20);

        printf("DRAW !!");
        printf("  GAME OVER");

    fprintf(scr,"%d %d\n",1,1);
 sumc+=1;
         sump+=1;
         return 1;
       // exit (0);
    }
    return 0;
}

void F()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(board[j] == 3)
            put_X_O('X',j);
        else if(board[j] == 5)
            put_X_O('O',j);
    }
}

void put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }

    gotoxy(x,y);
    printf("%c",ch);
}
