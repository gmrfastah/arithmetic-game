#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define MAX 5
#define N 40

int last,x;
char name[N][31];
int addscore[N],subtractscore[N], multiplyscore[N],allinall[N];

int gotoxy(int x, int y);
void score(int k, int l);
int menu();
void addition();
void subtraction();
void multiplication();
void totalscore();
void upload();
void download();
void makempty();
int isfull();
int isempty();
void secmenu();
void insertname();
void old();
void gettotal();

int main()
{
    int g;
    makempty();
    download();
    printf("Welcome to The Nerdiest Game!!!\n");
    printf("Press 1 to Continue:\n");
    scanf("%d",&g);
    if(g==1){
    while(1)
    {
      system("cls");
      gettotal();
      switch(menu())
      {
       case 1 : system("cls");insertname();break;
       case 2 : system("cls");old();break;
       case 3 : upload();exit(0);break;
      }
    }
    }
    else
    {
        getch();
    }
}

int menu()
{
    int op;
    system("cls");
    printf("1.) New Member\n");
    printf("2.) Old Member\n");
    printf("3.) Exit\n");
    printf("Choose from 1 to 3:\n");
    scanf("%d",&op);
    return op;
}

void insertname()
{
    if(isfull())
    {
        printf("\nFull");
    }
    else
    {
        system("cls");
        last++;
        printf("Enter your in-game name: ");
        scanf("%s",&name[last]);
        printf("Name is successflly created.");
    }
}

void old()
{
    if(isempty())
    {
        printf("No name yet.");
    }
    else
    {
        int i, flag=0;
        char temp[31];
        char nickname[31];

        system("cls");
        printf("Enter your in-game name: ");
        scanf("%s", &nickname);

        for (i = 0; i < last + 1; i++)
        {
            strcpy(temp, name[i]);
            if(strcmp(nickname, temp) == 0)
            {
                x = i;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            secmenu();
        else
            {
                printf("Invalid IGN");
                getch();
            }
    }
}

void secmenu()
{
gettotal();
int op;
system("cls");
printf("The Game\n");
printf("1.) Addition\n");
printf("2.) Subtraction\n");
printf("3.) Multiplication\n");
printf("4.) Show Scores\n");
printf("5.) Exit\n");
printf("Select(1-5):\n");
scanf("%d",&op);
switch(op)
{
    case 1: addition();break;
    case 2: subtraction();
    case 3: multiplication();
    case 4: totalscore();
    case 5: upload();exit(0);break;
    default:
        {
            printf("Error! 1 to 4 only.");
            getch();
            secmenu();
        }
}

}

void addition()
{
    int a,b,ans,i,corA=0,trA=0;
    srand(time(NULL));

    for (i=0;i<MAX;i++)
    {
        a = rand() %100;
        b = rand() %100;
        system("cls");
        score(corA, trA);
        gotoxy(5,5);
        printf("What is %d + %d? ",a,b);
        scanf("%d",&ans);

        if(ans == a+b)
        {
            gotoxy(6,5);
            printf("Correct!");
            corA++;
        }
        else
        {
            gotoxy(6,5);
            printf("Wrong!, The Correct answer is %d",a+b);
        }
        trA++;
        score(corA,trA);
        addscore[x]=corA;
    }
    secmenu();
}

void subtraction()
{
    int a,b,ans,i,corS=0,trS=0;
    srand(time(NULL));

    for (i=0;i<MAX;i++)
    {
        a=rand()%100;
        b=rand()%50;
        system("cls");
        score(corS,trS);
        gotoxy(5,5);
        printf("What is %d - %d? ",a,b);
        scanf("%d",&ans);

        if(ans == a-b)
        {
            gotoxy(6,5);
            printf("Correct!");
            corS++;
        }
        else
        {
            gotoxy(6,5);
            printf("Wrong!, The Correct answer is %d",a+b);
        }
        trS++;
        score(corS,trS);
        subtractscore[x]=corS;
    }
    secmenu();
}

void multiplication()
{
    int a,b,ans,i,corM=0,trM=0;
    srand(time(NULL));

    for (i=0;i<MAX;i++)
    {
        a=rand()%100;
        b=rand()%100;
        system("cls");
        score(corM,trM);
        gotoxy(5,5);
        printf("What is %d x %d? ",a,b);
        scanf("%d",&ans);

        if(ans == a*b)
        {
            gotoxy(6,5);
            printf("Correct!");
            corM++;
        }
        else
        {
            gotoxy(6,5);
            printf("Wrong!, The Correct answer is %d",a+b);
        }
        trM++;

        score(corM,trM);
        multiplyscore[x]=corM;
    }
    secmenu();
}

void score(int k, int l)
{
    gotoxy(3,30);printf("Score: %d",k);
    gotoxy(4,30);printf("Tries: %d",l);
}

int gotoxy(int x, int y)
{
    printf("\e[%d;%df",x,y);
}

void totalscore()
{
   int i,e;
    system("cls");
    gotoxy(1, 1); printf("Rank");
    gotoxy(1, 6); printf("Name");
    gotoxy(1, 20); printf("Addition");
    gotoxy(1, 40); printf("Subtraction");
    gotoxy(1, 60); printf("Multiplication");
    gotoxy(1, 80); printf("Total Score");
    for(i=0;i<last + 1;i++)
    {
        gotoxy(2 + i, 1); printf("%d.)", i + 1);
        gotoxy(2 + i, 6); printf("%s", name[i]);
        gotoxy(2 + i, 20); printf(" %3d", addscore[i]);
        gotoxy(2 + i, 40); printf(" %4d", subtractscore[i]);
        gotoxy(2 + i, 60); printf(" %6d", multiplyscore[i]);
        gotoxy(2 + i, 80); printf(" %4d\n", allinall[i]);
    }
    printf("Press 1 to go back.\n");
    scanf("%d",&e);
    if(e==1)
    {
        secmenu();
    }
    getch();
}


void upload()
{
  FILE *fp;
  int i;
  fp=fopen("totalscore.dbf","w+");
  for(i=0;i<last+1;i++)
    {
     fprintf(fp,"%s\n",name[i]);
     fprintf(fp,"%d\n",addscore[i]);
     fprintf(fp,"%d\n",subtractscore[i]);
     fprintf(fp,"%d\n",multiplyscore[i]);
     fprintf(fp,"%d\n",allinall[i]);
    }
   fclose(fp);
}

void download()
{
   FILE *fp;
   fp=fopen("totalscore.dbf","r+");
   int i=0;
   while(!feof(fp))
    {
      last++;
      fscanf(fp,"%s\n",&name[i]);
      fscanf(fp,"%d\n",&addscore[i]);
      fscanf(fp,"%d\n",&subtractscore[i]);
      fscanf(fp,"%d\n",&multiplyscore[i]);
      fscanf(fp,"%d\n",&allinall[i]);
      i++;
    }
    fclose(fp);

}

void makempty()
{
   last=-1;
}

int isfull()
{
   return(last==N-1);
}

int isempty()
{
   return(last==-1);
}

void gettotal()
{
    int i;
    for(i=0;i<last+1;i++)
    {
        allinall[i] = addscore[i] + subtractscore[i] + multiplyscore[i];
    }
}

//edit lang to


