#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;  
void drawline(int x0,int y0,int x1,int y1)  
{  
    int dx,dy,pk,xk,yk;
    dx=x1-x0;
    dy=y1-y0;
    xk=x0;
    yk=y0;
    pk=2*dy-dx;
    while(xk<x1)
    {  
        if(pk>=0)  
        {  
            putpixel(xk,yk,7);  
            yk=yk+1;  
            pk=pk+2*dy-2*dx;  
        }  
        else  
        {  
            putpixel(xk,yk,7);  
            pk=pk+2*dy;
		}
        xk=xk+1;
        cout<<"("<<xk<<","<<yk<<")"<<" and pk is "<<pk<<endl; 
    }
	
}  
int main()  
{  
    int x0, y0, x1, y1;  
    initwindow(800,800); 
    cout<<"Enter co-ordinates of first point:"<<endl;  
    cin>>x0;
	cin>>y0; 
    cout<<"Enter co-ordinates of second point:"<<endl;  
    cin>>x1;
	cin>>y1;
    drawline(x0, y0, x1, y1);  
    getch();
	return 0;
}

