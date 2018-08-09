
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n,load;
int w[15],v[105],dp[(1<<10)+5],tmp[(1<<10)+5];
int judge(int s){
    int i,j,sum;
    sum=0;
    memset(v,0,sizeof(v));
    v[0]=1;
    for(i=0;i<n;i++)
        if((1<<i)&s){
            sum+=w[i];
            if(sum>load)
                return 0;
          for(j=load;j>=w[i];j--)
                if(v[j-w[i]])
                    v[j]=1;//j就是加上当前这个货物的质量,记录下来,v数组记录的就是左右货物各种组合的重量
        }
 //   for(i=0;i<=load;i++)
   //     if(v[i]&&sum-i<=load)//被注释掉的情况是考虑的是两辆车运送到情况，如果只有一辆车，就不需要
            return 1;
   // return 0;
}
int main(){
    int i,j,k,cas;
    cas=1;
    k=0;
        scanf("%d%d",&n,&load);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(i=1;i<(1<<n);i++)
            if(judge(i))                            //判断每个状态的体积能不能一次运走
                tmp[k++]=i;
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(i=0;i<k;i++)
            for(j=(1<<n)-1;j>=0;j--){               //以每个状态为体积，价值为1，进行01背包
              if(!(tmp[i]&j))
                    dp[j|tmp[i]]=min(dp[j|tmp[i]],dp[j]+1);
            }
        printf("Scenario #%d:\n%d\n\n",cas++,dp[(1<<n)-1]);

    return 0;
}

