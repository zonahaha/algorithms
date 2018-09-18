#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s[42][42];
int w,h,starti,startj,endi,endj,res,row,col;

int direction;//表示方向，1--左，2--上，3--右，4--下,默认左



void go()
{
    int i,j;
    if(direction==1)
    {
        if(s[row+1][col]=='#')
        {
            if(s[row][col-1]=='#')
            {
                if(s[row-1][col]=='#')
                {
                    col=col+1;//向右
                    direction=3;
                    res++;
                    return;
                }
                else
                {
                    row=row-1;//向上
                    direction=2;
                    res++;
                    return;
                }
            }
            else
            {
                col=col-1;//向左
                direction=1;
                res++;
                return;
            }
        }
        else
        {
            row=row+1;//向下
            direction=4;
            res++;
            return;
        }
    }
    if(direction==2)
    {
        if(s[row][col-1]=='#')
        {
            if(s[row-1][col]=='#')
            {
                if(s[row][col+1]=='#')
                {
                    row=row+1;//向下走
                    direction=4;
                    res++;
                    return;
                }
                else
                {
                    col=col+1;//向右走
                    direction=3;
                    res++;
                    return;
                }
            }
            else
            {
                row=row-1;//向上走
                direction=2;
                res++;
                return;
            }
        }
        else
        {
            col=col-1;//向左走
            direction=1;
            res++;
            return;
        }
    }
    if(direction==3)
    {
        if(s[row-1][col]=='#')
        {
            if(s[row][col+1]=='#')
            {
                if(s[row+1][col]=='#')
                {
                    col=col-1;//向左
                    direction=1;
                    res++;
                    return;
                }
                else
                {
                    row=row+1;//向下
                    direction=4;
                    res++;
                    return;
                }
            }
            else
            {
                col=col+1;//向右
                direction=3;
                res++;
                return;
            }
        }
        else
        {
            row=row-1;//向上
            direction=2;
            res++;
            return;
        }
    }
    if(direction==4)
    {
        if(s[row][col+1]=='#')
        {
            if(s[row+1][col]=='#')
            {
                if(s[row][col-1]=='#')
                {
                    row=row-1;//向上
                    direction=2;
                    res++;
                    return;
                }
                else
                {
                    col=col-1;//向左
                    direction=1;
                    res++;
                    return;
                }
            }
            else
            {
                row=row+1;//向下
                direction=4;
                res++;
                return;
            }
        }
        else
        {
            col=col+1;//向右
            direction=3;
            res++;
            return;
        }
    }
}

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        res=1;
        scanf("%d %d",&w,&h);
        for(i=0;i<h;i++)
        {
            scanf("%s",s[i]);
            //printf("%s\n",s[i]);
        }
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(s[i][j]=='S')
                {
                    starti=i;
                    startj=j;
                    row=i;
                    col=j;
                    if(i==0)
                    {
                        direction=4;
                    }
                    if(i==h-1)
                    {
                        direction=2;
                    }
                    if(j==0)
                    {
                        direction=3;
                    }
                    if(j==w-1)
                    {
                        direction=1;
                    }
                }
                if(s[i][j]=='E')
                {
                    endi=i;
                    endj=j;
                }
            }
        }
        while(1)
        {
            go();
            if(row==endi && col==endj)
            {
                break;
            }
        }
        printf("%d\n",res);
    }



    return 0;
}
