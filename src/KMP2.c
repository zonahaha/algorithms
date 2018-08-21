Skip to content
 
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 @zonahaha
Sign out
 Unwatch 1
 Star 0  Fork 0 zonahaha/algorithms
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Insights  Settings
Browse files
Create KMP.c

 master
@zonahaha
zonahaha committed 3 minutes ago Verified
1 parent 974ed69 commit f646a57df3d00e0741d485440731662f2a04081f
Unified Split
Showing  1 changed file  with 46 additions and 0 deletions.
View  
46  src/KMP.c
@@ -0,0 +1,46 @@
 #include <stdio.h>
 #include <malloc.h>
 #include <mem.h>
 #include <string.h>

 void getNext(char* T,int *next){
     int i=1;
     int j=0;
     next[0]=next[1]=0;
     while(i<strlen(T)){
         if(j==0||T[i]==T[j]){
             i++;
             j++;
             if(T[i]!=T[j])///////////////这三行是主要区别
                next[i]=j;/////////////
            else next[i]=next[j];///////////
         }
         else{
             j=next[j];
         }
     }
 }
 int KMP(char* S, char* T){
     int length=strlen(S);
     int i=0;
     int j=1;
     int* next=(int*)malloc(sizeof(int)*(length+1));
     getNext(T,next);
     while(i<=length&&j<=strlen(T)){
         if(S[i]==T[j-1]||j==0){
             i++;
             j++;
         }
         else{
             j=next[j];
         }
     }
     if(j>strlen(T))return i-strlen(T)+1;
     else return 0;
 }
 int main() {
     char* S=(char *)malloc(sizeof(char)*100);
     char* T=(char *)malloc(sizeof(char)*100);
     scanf("%s",S);
     scanf("%s",T);
     printf("%d",KMP(S,T));
     return 0;
 }
 
