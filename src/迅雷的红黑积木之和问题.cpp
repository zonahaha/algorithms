#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int main() {
   int r,b;
   cin>>r>>b;
   int max=INT8_MIN;
   int num=0;
   for(int i=0;i<=7;i++){
       int add=i*r+b*(7-i);
       if(add<0){
           if(max<add){
               max=add;
               num=i;
           }

       }
   }

    cout <<max*2+r*(num>=3?3:num)+b*(num>=3?0:3-num);
    return 0;
}
