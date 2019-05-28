#include<bits/stdc++.h>
using namespace std;
int check(int d,int m,int y)
{
    if(m<1 || m>12)
    {
        cout<<"invalid date";
        return 0;
    }
    if(d<1 || d>31)
    {
        cout<<"invalid date";
        return 0;
    }
    if(m==2)
    {
        if((y%4==0)&&(y%100!=0)||y%400==0)
        {
            if(d>29)
            {
                cout<<"february has only 29 days";
                return 0;
            }
        }
        else
        {
            if(d>28)
            {
                cout<<"februry has only 28 days";
                return 0;
            }
        }
    }
    if(m==4 || m==6 || m==9 || m==11)
    {
        if(d>30)
        {
            cout<<"invalid date";
            return 0;
        }
    }
    return 1;
}
int main()
{
    int d,m,y,f,y1,y2,y3,c,l;
    cin>>d>>m>>y;
    if(!check(d,m,y))
        return 0;

    l=y;
    y--;
    //cout<<y<<"\n";
    y2=y%100;
    //cout<<y2<<"\n";
    y1=y-y2;
    //cout<<y1<<"\n";
    y3=y1%400;
    //cout<<y3<<"\n";
    switch(y3)
    {
        case 100: f=5;
                  break;
        case 200: f=3;
                  break;
        case 300: f=1;
                  break;
        case 0: f=0;
                break;
        default: cout<<"not valid date:";
                 return 0;
    }
    y3=y2/4;
    //cout<<y3<<"\n";
    y2=y2-y3;
    //cout<<y2<<"\n";
    f=f+2*y3+y2;
    int a[]={3,0,3,2,3,2,3,3,2,3,2,3};
    int b[]={3,1,3,2,3,2,3,3,2,3,2,3};
    if((l%4==0 && l%100!=0)||(l%400==0))
    {
        m=m-1;
        for(int i=0;i<m;i++)
            f=f+b[i];
    }
    else
    {
        m--;
        for(int i=0;i<m;i++)
            f=f+a[i];
    }
    f=f+d%7;
    //cout<<f<<"\n";
    f=f%7;
    switch(f)
    {
        case 0: cout<<"sunday";
                break;
        case 1: cout<<"monday";
                break;
        case 2: cout<<"tuesday";
                break;
        case 3: cout<<"wednesday";
                break;
        case 4: cout<<"thursday";
                break;
        case 5: cout<<"friday";
                break;
        case 6: cout<<"saturay";
                break;
    }
}
