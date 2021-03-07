#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void bezier(int x[4], int y[4])
{
	double t;
	for(t=0.0;t<1.0;t+=0.0005)
	{
		double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		putpixel(xt,yt,BLUE);
	}

//	for(int i=0;i<4;i++)
//		putpixel(x[i],y[i],YELLOW);
	for(int i=0;i<3;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}	
	
}

int main()
{

	initwindow(800,800);
	int x[4],y[4];
	int i;
	cout<<"Enter x coordinates"<<endl;
	for(i=0;i < 4;i++)
 	{
		cin>>x[i];
	}
	cout<<"Enter y coordinates"<<endl;
	for(i=0;i < 4;i++)
 	{
		cin>>y[i];
	}
    bezier(x,y);
    getch();
	closegraph();
	return 0;
}

