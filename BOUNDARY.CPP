#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void boundaryfill(int x, int y,int fill_c, int boundary_c)
{ int current;
 current = getpixel(x,y);
 if(current != boundary_c && current != fill_c)
 {
 putpixel(x,y,fill_c);
 boundaryfill(x,y+1,fill_c,boundary_c);
 boundaryfill(x,y-1,fill_c,boundary_c);
  boundaryfill(x+1,y,fill_c,boundary_c);
   boundaryfill(x-1,y,fill_c,boundary_c);
   }
 }

void ff(int x,int y,int old_c, int new_c)
{
int current;
current = getpixel(x,y);
if(current == old_c)
{
putpixel(x,y,new_c);
ff(x,y+1,old_c,new_c);
ff(x,y-1,old_c,new_c);
ff(x+1,y,old_c,new_c);
ff(x-1,y,old_c,new_c);
}
}


void main() {
	int x,y,x1,y1,r,gd=DETECT,gm,d;
	x=0;
	initgraph(&gd,&gm,"..\\bgi");
	printf("Enter radius");
	scanf("%d",&r);
	printf("Enter centre coordinates (x,y & x1,y1)");
	scanf("%d %d %d %d",&x,&y,&x1,&y1);
	circle(x,y,r);
	circle(x1,y1,r);
	boundaryfill(x,y,5,15);
	ff(x1,y1,0,9);
	getch();
	closegraph();
}