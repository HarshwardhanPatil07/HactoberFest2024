#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

//Structure of ball
struct ball{
 int x ;
 int y ;
 int radius;
 int speedx;
 int speedy;
}ball;

//Structure of Bat(b1,b2)
struct bat{
 int x;
 int y;
 int l;
 int w;
 int s;
}b1,b2;

struct score{
 int s;
}s1,s2;

char buff[3][100];
char t[15];
char n[25];
char k[50];
int i=0;

void initialize(){

 replay:

 cleardevice();

 ball.x=getmaxx()/2;
 ball.y=getmaxy()/2;
 ball.radius= 7;
 ball.speedx = 5;
 ball.speedy = 8;

 b1.x=20;
 b1.y=237;
 b1.l=40;
 b1.w=4;
 b1.s=13;

 b2.x=620;
 b2.y=237;
 b2.l=40;
 b2.w=4;
 b2.s=13;

 s1.s=0;
 s2.s=0;

 setbkcolor(GREEN);

 settextstyle(8, HORIZ_DIR,6);
 sprintf(k,"PING PONG GAME");
 outtextxy(60,(getmaxy()/2)-75,k);
 delay(2000);

 while(1){
 cleardevice();

 settextstyle(0,HORIZ_DIR,1);
 sprintf(t,"A - %d",s1.s);
 outtextxy(10,450,t);
 sprintf(t,"B - %d",s2.s);
 outtextxy(560,450,t);

 settextstyle(3,HORIZ_DIR,2);
 sprintf(n,"Made BY SAMAGRA GUPTA");
 outtextxy(getmaxx()/2 -115,450,n);

 bar(0,443,getmaxx(),443);

 if(ball.x<b1.x){
 ball.x=getmaxx()/2;
 ball.y=getmaxy()/2;
 s2.s=s2.s+1;
 sound(1000);
 delay(75);
 nosound();
 }
 if(ball.x>b2.x+b2.w){
 ball.x=getmaxx()/2;
 ball.y=getmaxy()/2;
 s1.s=s1.s+1;
 sound(1000);
 delay(75);
 nosound();
 }
 if(ball.y<0 || ball.y>434){
     ball.speedy = ball.speedy * -1;
 }
 ball.x = ball.x + ball.speedx;
 ball.y = ball.y + ball.speedy;
 setcolor(WHITE);
 setfillstyle(SOLID_FILL, WHITE);
 circle(ball.x,ball.y,ball.radius);
 floodfill(ball.x,ball.y,WHITE);

 bar(b1.x,b1.y,b1.x+b1.w,b1.y+b1.l);
 bar(b2.x,b2.y,b2.x+b2.w,b2.y+b2.l);


 if(b1.y+b1.l-ball.y>0){
 if(b1.x+b1.w+4-ball.x>0){
 if(b1.y<ball.y){
  ball.speedx = ball.speedx * -1;
  setbkcolor(BLUE);
  sound(200);
  delay(50);
  nosound();
 }
 }
 }

 if(b2.x-4<ball.x){
 if(b2.y<ball.y){
 if(b2.y+b2.l>ball.y){
 ball.speedx=ball.speedx * -1;
 setbkcolor(RED);
 sound(200);
 delay(50);
 nosound();
 }
 }
 }

 if(kbhit()){
 int c=getch();
  if(b1.y+b1.l<=443){
  if(c==122)
  {
  b1.y=b1.y+b1.s;
  }
  }
  if(b1.y>=0){
  if(c==97){
  b1.y=b1.y-b1.s;
  }
  }
  if(b2.y+b2.l<=443){
  if(c==109){
  b2.y=b2.y+b2.s;
  }
  }
  if(b2.y>=0){
  if(c==106){
  b2.y=b2.y-b2.s;
  }
  }
 }

 delay(50);

 if(s1.s==5 || s2.s==5){
  FILE *o;
  o=fopen("Q.txt","a");
  fprintf(o,"\nA - %d \t B - %d",s1.s,s2.s);
  fclose(o);

  o=fopen("Q.txt","r");
  fseek(o,-43,2);
  i=0;
  while(!feof(o)){

  fgets(buff[i],20,o);
  i++;
  }
  fclose(o);

  cleardevice();
  setbkcolor(8);
  settextstyle(8,HORIZ_DIR,9);
  outtextxy(40,50,"GAME OVER");

  settextstyle(3,HORIZ_DIR,2);
  outtextxy(40,250,"PLAY AGAIN(p)");
  outtextxy(520,250,"QUIT(q)");

  settextstyle(4,HORIZ_DIR,5);
  outtextxy(240,310,"SCORES");

  settextstyle(5,HORIZ_DIR,4);
  outtextxy(200,350,buff[0]);

  outtextxy(200,380,buff[1]);

  outtextxy(200,410,buff[2]);

  if(kbhit){
  int c=getch();
  if(c==112)
  {goto replay;}

  else if(c==113)
  { exit(0); }
  }
 }

 if(kbhit()){
  int ch=getch();
  if(ch==113){
   FILE *p;
   p=fopen("Q.txt","a");
   fprintf(p,"\nA - %d \t B - %d",s1.s,s2.s);
   fclose(p);
   exit(0);
  }
 }
 }
}


int main(){
   int gd = DETECT,gm;
   initgraph(&gd, &gm, "C:/TURBOC3/bgi");
   initialize ();
   getch();
   closegraph();
   return 0;
}
