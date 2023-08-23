#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
int rx,ry,xc,yc,x,y,gd=DETECT,gm;
float p1,p2,dx,dy;
printf("Enter radius rx &ry,xc,yc\n");
scanf("%d%d%d%d",&rx,&ry,&xc,&yc);
x=0;y=ry;
initgraph(&gd,&gm,"..//bgi");
p1=ry*ry-rx*rx*ry*ry+0.25*rx*rx;
do
{
putpixel(xc+x,yc+y,7);
putpixel(xc+x,yc-y,7);
putpixel(xc-x,yc+y,7);
putpixel(xc-x,yc-y,7);
//p1=ry*ry-rx*rx*ry*ry+0.25*rx*rx;
dx=2*ry*ry*x;
dy=2*rx*rx*y;
if(p1<0)
{
x+=1;
p1=p1+2*ry*ry*rx+ry;
}
else
{
x+=1;
y=y-1;
p1=p1+dx-dy*ry*ry;
}
}
while(dx<dy);
p2=rx*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)-rx*rx*ry*ry;
while(dx>=dy)
{
putpixel(xc+x,yc+y,7);
putpixel(xc+x,yc-y,7);
putpixel(xc-x,yc+y,7);
putpixel(xc-x,yc-y,7);
if(p2>0)
{
x=x;
y=y-1;
p2=p2-2*rx*rx*y+rx*rx;
}
else
{
x=x+1;
y=y-1;
p2=p2+dx-dy+rx*ry;
}
}
closegraph();
getch();
return 0;
}