/*
监狱风云
描述
监狱中所有人按照每两个人为一对，按顺序站队。监狱长需要将新来的人（偶数个）插入到原来队列中。因此设计一个算法，给定一个包含n个
节点的数列并且按从小到大的顺序排列，其中每个节点是一对字符并且顺序有小到大排列，比如（a,b）然后插入一个新的节点组成一个新的数
列，确保该数列仍然按照顺序排列并且数列中的节点没有重合

输入描述
给定一个包含n个节点，(n<=10)且按照顺序存放的数列和要插入的节点，节点内部数据范围为[a~z]。

输出描述
返回一个新的数列。

样例输入 1   样例输出 1
abeg         abcdeg
cd

样例输入 2   样例输出 2
abeg         aceg
bc

样例输入 3   样例输出 3
abeg         ag
be
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char* s1=(char*)malloc(sizeof(char)*21);
    char* s2=(char*)malloc(sizeof(char)*11);
    scanf("%s",s1);
    scanf("%s",s2);
    if(s1==NULL){
        s1=s2;
        return 0;
    }
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(int i=0;i<len2;i++){
        for(int j=0;j<=len1;j++){
            if(j==len1){
                s1[len1++]=s2[i];
              //  printf("\nend%s",s1);
                break;
            }
            if(s2[i]==s1[j]){
                int k=j;
                while(k<len1) {

                    s1[k] = s1[k+1];
                    //  printf("%c", s1[k]);
                    k++;
                }
                len1-=1;
              //  printf("\nequal%s",s1);
                break;
            }
            else if(s2[i]<s1[j]){
                int k=len1;
                while(j<k) {
                    s1[k] = s1[k - 1];
                    k--;
                }
                len1+=1;
                s1[j]=s2[i];
             //   printf("\nless%s", s1);
                break;
            }
        }
    }
    s1[len1]='\0';
    printf("%s",s1);
    return 0;
}


//////////////////////////////////////////命令行版,ide命令行写abeg gh就可以了，argv[0]是文件地址，argv[1]，argv[2]分别是第1个第二个参数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char ** argv){
    char* s1=(char*)malloc(sizeof(char)*21);
    char* s2=(char*)malloc(sizeof(char)*11);
    // scanf("%s",s1);
    //  scanf("%s",s2);
  //  printf("arghv%s",argv[1]);
    s1=argv[1];
    s2=argv[2];
   // printf("\n s1%s",s1);
   // printf("\n s2%s",s2);
    if(s1==NULL){
        s1=s2;
        return 0;
    }
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(int i=0;i<len2;i++){
        for(int j=0;j<=len1;j++){
            if(j==len1){
                s1[len1++]=s2[i];
                //  printf("\nend%s",s1);
                break;
            }
            if(s2[i]==s1[j]){
                int k=j;
                while(k<len1) {

                    s1[k] = s1[k+1];
                    //  printf("%c", s1[k]);
                    k++;
                }
                len1-=1;
                //  printf("\nequal%s",s1);
                break;
            }
            else if(s2[i]<s1[j]){
                int k=len1;
                while(j<k) {

                    s1[k] = s1[k - 1];

                    k--;
                }
                len1+=1;
                s1[j]=s2[i];
                //   printf("\nless%s", s1);
                break;
            }

        }
    }
    s1[len1]='\0';
    printf("\ns1%s",s1);
    return 0;
}
