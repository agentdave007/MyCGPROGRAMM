#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

typedef unsigned int outcode;
enum
{ 
	TOP=1,
	BOTTOM=2,
	RIGHT=4,
	LEFT=8
};
float xmin,xmax,ymin,ymax;

outcode CompOutCode(float x,float y)
{
	outcode code = 0;
	if(y>ymax)
		code|=TOP;
	else if(y<ymin)
		code|=BOTTOM;
			
	if(x>xmax)
		code|=RIGHT;				
	else if(x<xmin)
		code|=LEFT;
		
	return code;
}
void clip(float x0,float y0,float x1,float y1)
{
	outcode outcode0,outcode1,outcodeOut;
	int accept = false,done = false;
	outcode0 = CompOutCode(x0,y0);
	outcode1 = CompOutCode(x1,y1);
	do{
		if(!(outcode0|outcode1))
		{
			accept = true;
			done = true;
		}
		else
			if(outcode0 & outcode1)
				done = true;
			else
			{
				float x,y;
				outcodeOut = outcode0?outcode0:outcode1;
				if(outcodeOut & TOP)
				{
					x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
					y = ymax;
				}
				else
					if(outcodeOut & BOTTOM)
					{
						x = x0+(x1-x0)*(ymin-y0)/(y1-y0);
						y = ymin;
					}
					else
					if(outcodeOut & RIGHT)
					{
						y = y0+(y1-y0)*(xmax-x0)/(x1-x0);
						x = xmax;
					}
					else
					{
						y = y0+(y1-y0)*(xmin-x0)/(x1-x0);
						x = xmin;
					}
					if(outcodeOut==outcode0)
					{
						x0 = x;
						y0 = y;
						outcode0 = CompOutCode(x0,y0);
					}
					else
					{
						x1 = x;
						y1 = y;
						outcode1 = CompOutCode(x1,y1);
					}
				}
			}
	while(done==false);
			
	if(accept)
		line(x0,y0,x1,y1);
	rectangle(xmin,ymin,xmax,ymax);
}
int main( )
{
	float x1,y1,x2,y2;
	/* request auto detection */
	int n,poly[14],i;
	cout<<"Enter the no of sides of polygon:";
		cin>>n;
	cout<<"Enter the coordinates of polygon"<<endl;
	for(i=0;i<2*n;i++)
	{
		cin>>poly[i];
	}
	poly[2*n]=poly[0];
	poly[2*n+1]=poly[1];
	cout<<"Enter the rectangular coordinates of clipping window"<<endl;
	cin>>xmin;
	cin>>ymin;
	cin>>xmax;
	cin>>ymax;
	initwindow(800,800);
	drawpoly(n+1,poly);
	rectangle(xmin,ymin,xmax,ymax);
	getch();
	cleardevice();
	for(i=0;i<n;i++)
		clip(poly[2*i],poly[(2*i)+1],poly[(2*i)+2],poly[(2*i)+3]);
	getch();
	closegraph();
	return 0;
}
