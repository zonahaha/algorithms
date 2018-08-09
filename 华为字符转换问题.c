#include<stdio.h>
#include<stdlib.h>
int main(){
    char*s=(char*)malloc(sizeof(char)*100);
    while(gets(s)){
        for(int i=0;s[i]!='\0';i++){
            if(s[i]<='Z'&&s[i]>='A')s[i]=s[i]-'A'+'a';
            else if(s[i]<='z'&&s[i]>='a')s[i]=s[i]-'a'+'A';
        }
        printf("%s",s);
    }
    return 0;
}
