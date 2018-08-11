#include <stdio.h>

int main()
{
    int i,j,n,k,s,maxv,maxk,minv,mink;
    int a[101],b[1001][2];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    j=0;
    maxk=mink=0;
    maxv=0;
    minv=10001;
    while(1)
    {
        maxv=0;
        minv=10001;
        for(i=0;i<n;i++)
        {
            if(a[i]>maxv)
            {
                maxv=a[i];
                maxk=i;
                //printf("maxk=%d\n",maxk);
                //printf("maxv=%d\n",maxv);
            }
            if(a[i]<minv)
            {
                minv=a[i];
                mink=i;
                //printf("mink=%d\n",mink);
                //printf("minv=%d\n",minv);
            }
        }
        if(j>=k || maxv-minv<=1 || maxk==mink)
        {
            s=maxv-minv;
            break;
        }
        b[j][0]=maxk+1;
        b[j][1]=mink+1;
        j++;
        a[maxk]--;
        //maxv--;
        a[mink]++;
        //minv++;
        //printf("a[maxk]=%d\n",a[maxk]);
        //printf("a[maxk]=%d\n",a[maxk]);
    }
    printf("%d %d\n",s,j);
    for(i=0;i<j;i++)
    {
        printf("%d %d\n",b[i][0],b[i][1]);
    }

    return 0;
}
