#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
struct point
{
	int x,y;
};

void hermite(point p1,point p4,double r1,double r4)
{
	float x,y,t;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		x=(2*t*t*t-3*t*t+1)*p1.x+(-2*t*t*t+3*t*t)*p4.x+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r4;
		y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p4.y+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r4;
		putpixel(x,y,BLUE);
	}
	putpixel(p1.x,p1.y,YELLOW);
	putpixel(p4.x,p4.y,YELLOW);
	line(p1.x,p1.y,p4.x,p4.y);
}

int main()
{
	initwindow(800,800);

	double r1,r4;
	point p1,p2;
	cout<<"enter 2 hermite points"<<endl;
	cin>>p1.x>>p1.y>>p2.x>>p2.y;
	cout<<"enter tangents at p1 and p4"<<endl;
	cin>>r1>>r4;
	hermite(p1,p2,r1,r4);

	getch();
	closegraph();
	return 0;
}
