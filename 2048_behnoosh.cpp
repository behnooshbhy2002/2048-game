#include<iostream>
#include <iomanip>
#include<conio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
int a[20][20];
int t[20][20];
int n;
int m;
int grade;
int temp_grade;
int check_east();
int check_west();
int check_north();
int check_south();
int move_east();
int move_west();
int move_north();
int move_south();
int addNumber();
int show_table();
int new_game();
int finish();
int temp();
int undo();
int undo_score();
int score(int b);
int win();
int gameover();
int show_scoretable();
int main()
{
    FILE*fptr;
    //FILE*f;
    int b;
    int c;
    /* f=fopen("scoreboard.txt" , "a");
    fread(&name,sizeof(char),1,f);
    fread(&grade,sizeof(int),1,f);
    fclose(f); */
    cout<<"welcome to 2048 game if you wanna continue your previous game please enter 1 for new game please enter 0 : "<<endl;
    cin>>b;
    if(b==0)
    {
    start:
    cout<<"please enter a proper name for yourself : "<<endl;
    char name;
    cin>>name;
    cout<<"please enter the number of rows you want : "<<endl;
    cin>>m;
    cout<<"please enter the number of columns you want : "<<endl;
    cin>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                a[i][j]=0;
            addNumber();
            addNumber();
         start2:
          show_table();
          show_scoretable();
          //undo_score();
          char jahat;
          while(1)
          {
          cin>>jahat;

          switch(jahat)
          {
              case 'e':
              if(check_east()==1)
              {
               move_east();
               addNumber();
               system("cls");
               show_table();
               show_scoretable();
              }
              break;
              case 'w':
              if(check_west()==1)
              {
                 move_west();
                 addNumber();
                 system("cls");
                 show_table();
                 show_scoretable();
              }
              break;
              case 'n':
              if(check_north()==1)
              {
                 move_north();
                 addNumber();
                 system("cls");
                 show_table();
                 show_scoretable();
              }
              break;
              case 's':
              if(check_south()==1)
              {
                 move_south();
                 addNumber();
                 system("cls");
                 show_table();
                 show_scoretable();
              }
              break;
              case 'u':
                undo();
                system("cls");
                show_table();
                undo_score();
                break;
              case 'ng':
                new_game();
                system("cls");
                show_table();
                break;
              case 'f':
                system("cls");
                finish();
                break;
            }
         fptr=fopen("2048_behnoosh.txt","wt");
         fwrite(&m,sizeof(int),1,fptr);
         fwrite(&n,sizeof(int),1,fptr);
         fwrite(a,sizeof(int),400,fptr);
         fwrite(&grade,sizeof(int),1,fptr);
         fwrite(&temp_grade,sizeof(int),1,fptr);
         fwrite(t,sizeof(int),400,fptr);
         fclose(fptr);

        /* f=fopen("scoreboard.txt" , "w");
         fwrite(&name,sizeof(char),1,f);
         fread(&grade,sizeof(int),1,f);
         fclose(f); */

         if(win()==1)
         {
            system("cls");
            cout<<name<<"you win";
            break;
         }
        if(gameover()==1){
            system("cls");
           finish();
            break;
            }
        }
    }
    if(b==1)
    {
         fptr=fopen("2048_behnoosh.txt","rt");
         if(!fptr){
                  cout<<"file does not found please play new game  "<<endl;
                  goto start;
         }
         fread(&m,sizeof(int),1,fptr);
         fread(&n,sizeof(int),1,fptr);
         fread(a,sizeof(int),400,fptr);
         fread(&grade,sizeof(int),1,fptr);
         fread(&temp_grade,sizeof(int),1,fptr);
         fread(t,sizeof(int),400,fptr);
         fclose(fptr);
         goto start2;
    }
}
int check_east()
{
    bool flag=0;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
        flag=1;
        if(a[i][j]!=0&&a[i][j+1]==0)
        flag=1;
    }
return flag;
}
int check_west()
{
        bool flag=0;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
        flag=1;
        if(a[i][j]==0&&a[i][j+1]!=0)
        flag=1;
}
return flag;
}
int check_north()
{
    bool flag=0;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
        flag=1;
        if(a[i][j]==0&&a[i+1][j]!=0)
        flag=1;
}
return flag;
}
int check_south()
{
    bool flag=0;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
        flag=1;
        if(a[i+1][j]==0&&a[i][j]!=0)
        flag=1;
}
return flag;
}
int move_east()
{
    temp();
    int t=1;
    bool flag;
    while(t<n){
    for(int i=0;i<m;i++)
    for(int j=n-1;j>0;j--)
    {
        if(a[i][j]==0&&a[i][j-1]!=0){
        a[i][j]=a[i][j-1];
        a[i][j-1]=0;
        }
    }
    t++;
    }

    for(int i=0;i<m;i++)
        for(int j=n;j>=0;j--)
    {
    if(a[i][j]==a[i][j-1]&&a[i][j]!=0)
    {
        a[i][j]=a[i][j]+a[i][j-1];
        int b=a[i][j];
        score(b);
        a[i][j-1]=0;
    }
    }
    t=1;
    while(t<n){
    for(int i=0;i<m;i++)
    for(int j=n-1;j>0;j--)
    {
        if(a[i][j]==0&&a[i][j-1]!=0){
        a[i][j]=a[i][j-1];
        a[i][j-1]=0;
        }
    }
    t++;
    }

return flag;}
move_west()
{
    temp();
    int t=1;
    bool flag;
    while(t<n){
    for(int i=0;i<m;i++)
    for(int j=0;j<n-1;j++)
    {
        if(a[i][j]==0&&a[i][j+1]!=0){
        a[i][j]=a[i][j+1];
        a[i][j+1]=0;
        }
    }
    t++;
    }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
    if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
    {
        a[i][j]=a[i][j]+a[i][j+1];
        int b=a[i][j];
        score(b);
        a[i][j+1]=0;
    }
    }
    t=1;
    while(t<n){
    for(int i=0;i<m;i++)
    for(int j=0;j<n-1;j++)
    {
        if(a[i][j]==0&&a[i][j+1]!=0){
        a[i][j]=a[i][j+1];
        a[i][j+1]=0;
        }
    }
    t++;
    }
}
move_north()
{
    temp();
    int t=1;
    bool flag;
    while(t<m){
    for(int i=0;i<m-1;i++)
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==0&&a[i+1][j]!=0){
        a[i][j]=a[i+1][j];
        a[i+1][j]=0;
        }
    }
    t++;
    }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
    if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
    {
        a[i][j]=a[i][j]+a[i+1][j];
        int b=a[i][j];
        score(b);
        a[i+1][j]=0;
    }
    }
    t=1;
    while(t<m){
    for(int i=0;i<m-1;i++)
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==0&&a[i+1][j]!=0){
        a[i][j]=a[i+1][j];
        a[i+1][j]=0;
        }
    }
    t++;
    }
}
int move_south()
{
    temp();
    int t=1;
    bool flag;
    while(t<m){
    for(int i=m-1;i>0;i--)
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==0&&a[i-1][j]!=0){
        a[i][j]=a[i-1][j];
        a[i-1][j]=0;
        }
    }
    t++;
    }

    for(int i=m-1;i>=0;i--)
        for(int j=0;j<n;j++)
    {
    if(a[i][j]==a[i-1][j]&&a[i][j]!=0)
    {
        a[i][j]=a[i][j]+a[i-1][j];
        int b=a[i][j];
        score(b);
        a[i-1][j]=0;
    }
    int t=1;
    while(t<m){
    for(int i=m-1;i>0;i--)
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==0&&a[i-1][j]!=0){
        a[i][j]=a[i-1][j];
        a[i-1][j]=0;
        }
    }
    t++;
    }
    }
}
int addNumber()
{
    int flag=1;
    while(flag==1){
  srand(time(NULL));
  int i=rand()%m;
  int j=rand()%n;
  if(a[i][j]==0){
    a[i][j]=2;
    flag=0;
  }
}
}
int temp()
{
   for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        t[i][j]=a[i][j];
}
int undo()
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
          a[i][j]=t[i][j];
}
}
int undo_score()
{
    cout<<"score : "<<temp_grade;
}
int new_game()
{
    for(int i=0;i<m;i++)
        for(int j=0; j<n;j++)
        a[i][j]=0;
}
int finish()
{
    cout<<"game over";
}
int score(int b)
{
    temp_grade=grade;
    grade+=b;
}
int gameover()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
        if(a[i][j]!=0)
            return 0;
        if(a[i][j]==a[i][j]||a[i][j]==a[i+1][j])
            return 0;
    }
    return 1;
}
int win()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]==2048)
            return 1;
        return 0;
}
int show_table()
{

      for(int i=0;i<m;i++)
       {
        cout<<" ";
             for(int j=0;j<n;j++){
             cout<<" "<<" "<<a[i][j];

                 }
                cout<<endl;
                }

    cout<<"east(e)     "<<"west(w)     "<<"north(n)     "<<"south(s)     "<<"undo(u)     "<<"new_game(ng)     "<<"finish(f)     "<<endl;
      }

int show_scoretable()
{
    cout<<"score : "<<grade<<endl;
}
