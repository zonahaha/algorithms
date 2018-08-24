#include<stdio.h>
#include<stdlib.h>
#include <mem.h>
#define n 9
#define MAX 65535
typedef int parth[n];
typedef int weightsum[n];
void dijkstra(int G[n][n], int v0, parth *P, weightsum *D){
    printf("%d",v0);
    int final[n];
    int k;
   for(int i=0;i<n;i++){
       final[i]=0;
       (*D)[i]=G[v0][i];//存储与v0有连线的顶点的权值
       (*P)[i]=0;//存储初始化路径为0
   }
   *D[v0]=0;
   final[v0]=1;
   for(int i=1;i<n;i++){
       int min=MAX;
       for(int w=0;w<n;w++){
           if(!final[w]&&(*D)[w]<min){
               min=(*D)[w];
               k=w;
           }
       }
       final[k]=1;
       printf("->%d",k);
       for(int w=0;w<n;w++){
           if(!final[w]&&min+G[k][w]<(*D)[w]){
               (*P)[w]=k;
               (*D)[w]=min+G[k][w];
              // printf("->%d",w);
           }
       }
   }
}
 int main(){
    int G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=MAX;
        }
    }
    for(int i=0;i<n;i++)G[i][i]=0;
    G[0][1]=1,G[0][2]=5;
    G[1][0]=1,G[1][2]=3,G[1][3]=7,G[1][4]=5;
    G[2][0]=5,G[2][1]=3,G[2][4]=1,G[2][5]=7;
    G[3][1]=7,G[3][4]=2,G[3][6]=3;
    G[4][1]=5,G[4][2]=1,G[4][3]=2,G[4][5]=3,G[4][6]=6,G[4][7]=9;
    G[5][2]=7,G[5][4]=3,G[5][7]=5;
    G[6][3]=3,G[6][4]=6,G[6][7]=2,G[6][8]=7;
    G[7][4]=9,G[7][5]=5,G[7][6]=2,G[7][8]=4;
    G[8][6]=7,G[8][7]=4;
    parth *P=(parth*)malloc(sizeof(parth));
    weightsum *D=(weightsum *)malloc(sizeof(weightsum));
    int i=0;
    while(i<n){
        (*P)[i]=0;
        (*D)[i++]=0;
    }

    dijkstra(G,0,P,D);
}
