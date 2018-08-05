
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s=(char*)malloc(sizeof(int)*11);
    gets(s);
    int len=strlen(s);
    int width= (len+4)/4;
    int blank=1;
    for(int i=0;i<3*width;i++){
        while(i<width)printf("%c",s[i++]);
        while(i<2*width-2){
            printf("\n%c",s[--len]);
            while(blank<width-1){
                printf(" ");
                blank++;
            }
            blank=1;
            printf("%c",s[i++]);
        }
        printf("\n");
        while(i<3*width-2){

            printf("%c",s[--len]);
            i++;
        }
    }

    return 0;

}

