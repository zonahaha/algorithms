#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define EMPTY
#define INF -65536
int w[15],v[15];//物品个数，物品质量weight,物品价值value
int dp[1000][1000]={0};
const int n=5;//物品个数
int main(){
    int C;//容量capability\
 
    for(int i=1;i<=n;i++)scanf("%d,",&v[i]);
    for(int i=1;i<=n;i++)scanf("%d,",&w[i]);
    scanf("%d",&C);
 
#ifdef EMPTY//要求价值最大化，可以不满
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=C;i++)dp[0][i]=0;
#else//必须装满
    dp[0][0]=0;
        for(int i=1;i<=C;i++)dp[0][i]=INF;
        for(int i=1;i<=n;i++)dp[i][0]=INF;
#endif
    for(int i=1;i<=C;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=w[j]<=i?max(dp[i][j-1],dp[i-w[j]][j-1]+v[j]):dp[i][j-1];
        }
    }
    cout<<dp[C][n]<<endl;
    return 0;
}
