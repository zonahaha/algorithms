#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define EMPTY
#define INF -65536
const int C=500;//容量capability
int n;//物品个数
int w[15],v[15];//物品个数，物品质量weight,物品价值value
int dp[C+1];
int main(){
    scanf("%d ",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    #ifdef EMPTY//要求价值最大化，可以不满
        for(int i=0;i<=C;i++)dp[i]=0;
    #else//必须装满
        dp[0]=0;
        for(int i=1;i<=C;i++)dp[i]=INF;
    #endif
     for(int i=1;i<=n;i++){
         for(int j=C;j>0;j--){
             dp[j]=w[i]<=j?max(dp[j],dp[j-w[i]]+v[i]):dp[j];
         }
     }
     cout<<dp[C]<<endl;
    return 0;
}

