#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;


int getdown(int n,int m){

    int res=0;
    ////////////////  vector<vector<bool>> v(n,vector<bool>(m,0));这一句就代替了下面两个循环
    vector<vector<bool>> v(n);
    for(int i=0;i<n;i++){
        v[i].resize(m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=!v[i][j];
            if((j-1>=0)&&(i-1>=0))v[i-1][j-1]=!v[i-1][j-1];//左上
            if(i-1>=0)v[i-1][j]=!v[i-1][j];//上
            if((j+1)<m&&(i-1)>=0)v[i-1][j+1]=!v[i-1][j+1];//右上
            if(j-1>=0)v[i][j-1]=!v[i][j-1];//左
            if(j+1<m)v[i][j+1]=!v[i][j+1];//右
            if(i+1<n)v[i+1][j]=!v[i+1][j];//右
            if((i+1)<n&&(j+1)<m)v[i+1][j+1]=!v[i+1][j+1];//右下
            if((i+1)<n&&(j-1)>=0)v[i+1][j-1]=!v[i+1][j-1];//左下
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j])res++;
        }
    }

    return res;
}

int main(){
  int t;
  cin>>t;
  int m,n;
  vector<int> res;
  while(t){
      cin>>n>>m;
      res.push_back(getdown(n,m));
      t--;
  }
  for(auto i:res)cout<<i<<endl;
   return 0;
}
