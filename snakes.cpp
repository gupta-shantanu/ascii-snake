#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include "graphics.h"
void gotoxy(short x, short y) {
/* positions cursor to coodinate (x,y) */
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int redraw(int arr[100][2],int le){

    int i=1;
        gotoxy(arr[0][0],arr[0][1]);
        printf("%s","+");
 for(;i<le;i++)
 {
               gotoxy(arr[i][0],arr[i][1]);
               if(!(i==(le-1)))
 printf("%s","#");
 else
 printf("%s","O");
                  } 
}
void movechange(int *x,int *y,int move)
{
     if(move==1||move==-1)
     *x=*x+move;
     else
     *y=*y+(move/2);
 }
 
void foodgained(int arr[100][2],int *le,int *fx,int *fy,int *s){
                      if(arr[*le-1][0]==*fx&&arr[*le-1][1]==*fy)
                      {
                      gotoxy(*fx=rand()%30 + 6,*fy=rand()%20 + 6);
                      printf("%s","X");
                      (*s)++;
                       gotoxy(50,0);
                       printf("Score: %d",*s);
                      arr[*le][0]= arr[*le-1][0];
                       arr[*le][1]= arr[*le-1][1];
                      (*le)++;
                      }
     }
void repaint(int arr[100][2],int move,int *le)
{
     int i=0;
        gotoxy(arr[0][0],arr[0][1]);
                  printf("%s"," ");
 for(i=0;i<*le-1;i++){   
                   arr[i][0]=arr[i+1][0];
                   arr[i][1]=arr[i+1][1];
                   }
 arr[*le-1][0]=arr[*le-2][0];
 arr[*le-1][1]=arr[*le-2][1];
 movechange(&arr[*le-1][0],&arr[*le-1][1],move);
 }
short collision(int arr[100][2],int le){
      int i,j;
      for(i=0;i<le-2;i++)
      {
                      if(arr[i][0]==arr[le-1][0]&&arr[le-1][1]==arr[i][1])
                      {
                        return 1;                                             
                      }
                     
      }
      return 0;
      }
   void reinit(int arr[100][2],int *fx,int *fy,int *le,int *s){
    gotoxy(*fx=rand()%30 + 1,*fy=rand()%30 + 1);
                      printf("%s ","X");
   int r=0;  
   *le=3;                 
    for(r=0;r<*le;r++)
    {
                     arr[r][0]=r+1;
                     arr[r][1]=0;
                     }
                     *s=0;
                     }

int main()
{
    textcolor(RED);
    int arr[100][2],le=0,move=1,r,t=0,fx,fy,over=0,s=0;
 reinit(arr,&fx,&fy,&le,&s);
    while(1){
             if(kbhit()){
             /*controls for the snake <ASDW> */
                       r=getch();
                       if(r=='w' && move!=2)
                       move=-2;
                       else if(r=='s' && move!=-2)
                       move=2;
                       else if(r=='d' && move!=-1)
                       move=1;
                       else if(r=='a' && move!=1)
                       move=-1; 
                         }
             Sleep(10);
             t++;
             if(t==10)
             {
             repaint(arr,move,&le);
             redraw(arr,le);
             foodgained(arr,&le,&fx,&fy,&s);
             if(collision(arr,le)){
                                    cprintf("Game Over-- X ---");
             getch();
             cprintf("Restart the game.....");
             getch();
            break;
             }
            
             t=0;
             }
             }
            
    return 0;
 }
