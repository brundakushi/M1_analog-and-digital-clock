# include <graphics.h>
# include <dos.h>
# include <stdio.h>
# include <conio.h>
# include <math.h>
# include <process.h>
void frame();
void draw_Numbers(int, int,int);
void line_at_angle(int, float, int);
void beep(int, int, int, int, int);
void main()
{
int gdriver=DETECT,gmode,errorcode;
struct time t,i;
int key, k=0, x,y,t_sec,t_min,midx,midy;
char tim[5];
float hour,ang_sec,ang_min,ang_hour;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
if(errorcode!=grOk)
{
printf("Graphics error %s",grapherrormsg(errorcode));
printf("press any key to halt.");
exit(1);
}
gettime(&t);
midx=getmaxx()/2;
midy=getmaxy()/2;
frame();
while(1)
{
if(kbhit())
{
key=getch();
if(key==27)
break;
}
gettime(&t);
if(t.ti_hour>=12)
hour=t.ti_hour-12
else
hour=t.ti_hour;
ang_sec=t.ti_sec*6;
ang_min=(t.ti_min*6)+(ang_sec/60);
ang_hour=(hour*30)+(ang_min/12);
setcolor(4);
setfillstyle(1,9);
circle(midx,midy,6);
line_at_angle(150,ang_min,2); /min/
setcolor(12);
setfillstyle(1,4);
line_at_angle(130,ang_hour,3); /hour/
setcolor(14);
line_at_angle(170,ang_sec,1); /sec/
line_at_angle(20,180+ang_sec,1); /sec/
setfillstyle(1,4);
setcolor(13);
x=520,y=460;
gettime(&t);
if(t.ti_hour>12)
{
outtextxy(x+80,y,"PM");
sprintf(tim,"%d",t.ti_hour-12);
}
else
{
outtextxy(x+80,y,"AM");
sprintf(tim,"%d",t.ti_hour);
}
outtextxy(x,y,tim);
outtextxy(x+16,y,":");
outtextxy(x+42,y,":");
sprintf(tim,"%d",t.ti_min);
outtextxy(x+26,y,tim);
sprintf(tim,"%d",t.ti_sec);
outtextxy(x+50,y,tim);
k++;
if(k==10)
{
k=0;
beep(100,50);
}
else
delay(100);
t_sec = t.ti_sec;
t_min = t.ti_min;
clear(x+50,y,x+70,y+8,0);
if(t_sec >= 59)
clear(x+26,y,x+46,y+8,0);
if(t_min >= 59)
clear(x,y,x+20,y+8,0);
setcolor(0);
setfillstyle(1,0);
line_at_angle(130,ang_hour-6,1);
line_at_angle(150,ang_min-4,1);
line_at_angle(170,ang_sec,1);
line_at_angle(20,180+ang_sec,1);
ang_sec++;
}
closegraph();
}
void frame()
{
int midx,midy,i;
float angle=0;
float x,y;
midx=getmaxx()/2;
midy=getmaxy()/2;
setlinestyle(1,1,3);
setcolor(2);
circle(midx,midy,223);
setcolor(15);
circle(midx,midy,220);
setcolor(12);
circle(midx,midy,217);
setlinestyle(1,1,3);
setfillstyle(1,2);
setcolor(4);
for(i=0;i<=60;i++)
{
x=cos((angle/180)*M_PI)*190;
y=sin((angle/180)*m_PI)*190;
if((int)angle%30!=0)
circle(midx+x,mid+y,2);
angle+=6;
}
angle=0;
setfillstyle(1,4);
setlinestyle(0,1,2);
for(i=0;i<12;i++)
{
setcolor(13);
x=cos((angle/180)*M_PI)*190;
y=sin((angle/180)*m_PI)*190;
setcolor(10);
draw_Numbers(midx+x, midy+y,i);
angle+=30;
}
}
void line_at_angle(int radius, float angle, int flag)
{
float x,y,x1,y1,x2,y2,x3,y3;
int midx,midy;
int poly1[10];
angle-=90;
midx=getmaxx()/2;
midy=getmaxy()/2;
x=cos((angle/180)*M_PI)*radius;
y=sin((angle/180)*m_PI)*radius;
setlinestyle(0,1,3);
if(flag==1)
line(midx,midy,midx+x,midy+y);
if(flag==2)
{
setlinestyle(0,1,1);
x2=cos(((angle+3)/180)M_PI)(radius-25);
y2=sin(((angle+3)/180)m_PI)(radius-25);
x3=cos(((angle-3)/180)M_PI)(radius-25);
y3=sin(((angle-3)/180)m_PI)(radius-25);
poly1[0]=midx;
poly1[1]=midy;
poly1[2]=midx+x2;
poly1[3]=midy+y2;
poly1[4]=midx+x;
poly1[5]=midy+y;
poly1[6]=midx+x3;
poly1[7]=midy+y3;
poly1[8]=midx;
poly1[9]=midy;
fillpoly(5,poly1);
setcolor(0);
x2=cos(((angle)/180)M_PI)(radius+1);
y2=sin(((angle)/180)m_PI)(radius+1);
x3=cos(((angle-4)/180)M_PI)(radius-25);
y3=sin(((angle-4)/180)m_PI)(radius-25);
line(midx+x2,midy+y2,midx+x3,midy+y3);
line(midx+x,midy+y,midx+x3,midy+y3);
}
else if(flag==3)
{
setlinestyle(0,1,1);
x2=cos(((angle+5)/180)M_PI)(radius-30);
y2=sin(((angle+5)/180)m_PI)(radius-30);
x3=cos(((angle-5)/180)M_PI)(radius-30);
y3=sin(((angle-5)/180)m_PI)(radius-30);
poly1[0]=midx;
poly1[1]=midy;
poly1[2]=midx+x2;
poly1[3]=midy+y2;
poly1[4]=midx+x;
poly1[5]=midy+y;
poly1[6]=midx+x3;
poly1[7]=midy+y3;
poly1[8]=midx;
poly1[9]=midy;
fillpoly(5,poly1);
setcolor(0);
x2=cos(((angle)/180)M_PI)(radius+1);
y2=sin(((angle)/180)m_PI)(radius+1);
x3=cos(((angle-6)/180)M_PI)(radius-30);
y3=sin(((angle-6)/180)m_PI)(radius-30);
line(midx+x2,midy+y2,midx+x3,midy+y3);
line(midx+x,midy+y,midx+x3,midy+y3);
}
}
void beep(int fre,int wait)
{
sound(fre);
delay(wait);
nosound();
}
void draw_Numbers(intx, int y, int position)
{
char stpos[5]="";
position+=3;
if(position>12)
position=position%12;
itoa(position,stpos,10);
outtextxy(x,y,stpos);
}
void clear(int x1, int y1, intx2, inty2, int col)
{
int x,y;
for(x=x1;x<=x2;x++)
for(y=y1;y<=y2;y++)
putpixel(x,y,col);
}