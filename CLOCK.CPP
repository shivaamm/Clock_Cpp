#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

#define arg_sec M_PI/30
#define arg_hour M_PI/6
#define arg_min M_PI/360
void main()
{
  int gd=DETECT,gm,sec=0,hour,min,x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;
  char *k[12]={"1","2","3","4","5","6","7","8","9","10","11","12"};
  struct time t;
  initgraph(&gd,&gm,"");
  setcolor(YELLOW);
  circle(300,200,200);
  circle(300,200,180);
  setfillstyle(1,RED);
  floodfill(300,390,YELLOW);
  settextstyle(DEFAULT_FONT,0,2);
//----------------------Constants----------------------//

  int a,b;
  for(int i=1;i<13;i++)
    {
	a=160*cos(arg_hour*i-M_PI_2);
	b=160*sin(arg_hour*i-M_PI_2);
	outtextxy(a+300,b+200,k[i-1]);
    }

//----------------------Constants----------------------//
/*****************************************************
		 1-Good
		 2-Small
		 3-Watse
		 4-caligraphy
		 5-cursive
		 6-good
		 7-excellent
		 8-Good
		 9-Big
		 10-Double
 ****************************************************/
 int dig_sec;
 char Time_Dig[14];
  while(!kbhit())
   {
       settextstyle(7,0,4);
      outtextxy(264,100,"Satya");
      settextstyle(7,0,1);
      outtextxy(278,280,"Quartz");
      setcolor(BLACK);
      line(300,200,x1+300,y1+200);
      line(300,200,x2+300,y2+200);
      line(300,200,x3+300,y3+200);
      gettime(&t);
      if(sec!=t.ti_sec)
	{
	   sound(5000);
	   delay(1);
	   nosound();
	}
      hour=t.ti_hour;
      sec=t.ti_sec;
      min=t.ti_min;
      Time_Dig[0]=hour/10+48;
      Time_Dig[1]=hour%10+48;
      Time_Dig[2]=':';
      Time_Dig[3]=min/10+48;
      Time_Dig[4]=min%10+48;
      Time_Dig[5]=':';
      Time_Dig[6]=sec/10+48;
      Time_Dig[7]=sec%10+48;
      Time_Dig[8]='\0';
      outtextxy(270,250,"ллллллллллллллллл");
      x1=150*cos(arg_sec*sec-M_PI_2)*0.98;
      y1=150*sin(arg_sec*sec-M_PI_2)*0.98;
      x2=150*cos(arg_sec*min-M_PI_2)*0.9;
      y2=150*sin(arg_sec*min-M_PI_2)*0.9;
      if(hour>12) hour-=12;
      x3=150*cos(arg_hour*hour-M_PI_2+arg_min*min)*0.6;
      y3=150*sin(arg_hour*hour-M_PI_2+arg_min*min)*0.6;
      setcolor(YELLOW);
      line(300,200,x1+300,y1+200);
      setcolor(CYAN);
      line(300,200,x2+300,y2+200);
      setcolor(WHITE);
      line(300,200,x3+300,y3+200);
      setcolor(YELLOW);
      outtextxy(270,250,Time_Dig);
      delay(50);

   }

  getch();
  closegraph();
  restorecrtmode();
}
