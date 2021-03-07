#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main()
{
	int xc,yc,r,pk,x,y;  
	initwindow(800,800); 
	cout<<"Enter the center co-ordinates"<<endl;
	cin>>xc>>yc;
	cout<<"Enter the radius of circle"<<endl;
	cin>>r;
	pk = 1 - r;
	x = 0;
	y = r;
	while(x < y)
	{
		putpixel(x+xc,y+yc,YELLOW);
		cout<<x+xc<<","<<y+yc<<endl;
		putpixel(-x+xc,y+yc,BLUE);
		cout<<-x+xc<<","<<y+yc<<endl;
		putpixel(x+xc,-y+yc,GREEN);
		cout<<x+xc<<","<<-y+yc<<endl;
		putpixel(-x+xc,-y+yc,RED);
		cout<<-x+xc<<","<<-y+yc<<endl;
		putpixel(y+xc,x+yc,BROWN);
		cout<<y+xc<<","<<x+yc<<endl;
		putpixel(-y+xc,x+yc,CYAN);
		cout<<-y+xc<<","<<x+yc<<endl;
		putpixel(y+xc,-x+yc,LIGHTGREEN);
		cout<<y+xc<<","<<-x+yc<<endl;
		putpixel(-y+xc,-x+yc,LIGHTRED);
		cout<<-y+xc<<","<<-x+yc<<endl;
		++x;
		if(pk < 0)
			pk = pk + (2*x) + 1;
		else
		{
			--y;
			pk = pk + (2*x) + 1 - (2*y);
		}
	}
	getch();
	closegraph();
	return 0;
}
