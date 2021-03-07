#include<graphics.h>
#include<conio.h>
void drawline(int x1,int y1,int x2,int y2)
{
	int x,y,i,j=1;
	float dx=x2-x1,dy=y2-y1;
	float m=dy/dx;
	if(dx>=dy)
	{
		i=dx;
	}
	else
	i=dy;
	dx=dx/i;
	dy=dy/i;
	x=x1;
	y=y1;
	while(j<=i)
	{
		putpixel(x,y,GREEN);
		x+=dx;
		y+=dy;
		j++;
	}
}
main()
{
	initwindow(800,800);
	int x1,x2,y1,y2;
	drawline(350,100,450,100);
	getch();
	closegraph();
}
