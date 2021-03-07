#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
void drawline(int x0, int y0, int x1, int y1) 
{ 
    float dx = x1-x0; 
    float dy = y1-y0; 
    
    float m=dy/dx;
    int i;
    if(m>1)
		i=dx;
	else
		i=dy;
    
    float xk = dx/i; 
    float yk = dy/i; 
  
    float x = x0; 
    float y = y0; 
    for (int j = 0; j <= i; j++) 
    { 
        putpixel (x,y,RED);
        cout<<"(x,y) = ("<<abs(x)<<","<<y<<")"<<endl;
        x += xk;
        y += yk;
    } 
} 
int main() 
{ 
    initwindow(800,800);
	int x0,x1,y0,y1;
	cout<<"Enter the value of x0 and y0 :"<<endl;
	cin>>x0>>y0;
	cout<<"Enter the value of x1 and y1 :"<<endl;
	cin>>x1>>y1;
	drawline(x0,y0,x1,y1);
	getch();
	closegraph();
	return 0;
} 
