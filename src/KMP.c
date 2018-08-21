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
            next[i]=j;
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
