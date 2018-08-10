#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
typedef struct timetokill{
    int time;
    string killer;
    string victim;
}timetokill;
int main(){
    int A,B,T,Q,M,N;
    int left,right,rank_score;
    int RankS[101]={0};
    cin>>T;
    while(T--){
        cin>>Q>>N>>M;//Q-player,N-rank scores,M-murder scores
        for(int i=0;i<N;i++){
            cin>>left>>right>>rank_score;
            while(right-left>0){
                RankS[right--]=rank_score;
            }
            RankS[left]=rank_score;
        }
        int MurderS[101]={0};
        int j=0;
        for(int i=0;i<M+1;i++){
            cin>>MurderS[i];
           // cout<<i<<"="<<MurderS[i]<<endl;
        }
        cin>>A>>B;//生存系数
        //struct timetokill *ttl=(struct timetokill*)malloc(sizeof(struct timetokill)*Q);
        struct timetokill ttl[120];
        for(int i=0;i<Q-1;i++){
            cin>>ttl[i].time>>ttl[i].killer>>ttl[i].victim;
        }
        map<string,int> playerScores;
        map<string,int> killcount;
        map<string,int> killscore;
        map<string,int>::iterator it;
        int t;string killname;string victimname;
        for(int i=0;i<Q-1;i++){
            t=ttl[i].time;
            killname=ttl[i].killer;
            victimname=ttl[i].victim;

            it=killcount.find(killname);
           if(it==killcount.end()){//这个杀手是第一次杀人
               killcount.insert(pair<string,int>(killname,1));
               killscore.insert(pair<string,int>(killname,0));
           }
           else killcount[killname]++;
           it=killcount.find(victimname);
           if(it==killcount.end()){//被杀之人没杀过人
               killcount.insert(pair<string,int>(victimname,0));
               killscore[victimname]=0;
               killscore[killname]+=MurderS[0];//被杀的人没杀过人，所以是murderS[0]
               playerScores.insert(pair<string,int>(victimname,RankS[Q-i] + t*A + B));
           }
           else {
                       if(killname!=victimname){                           
                           if(killcount[victimname]<M)killscore[killname]+=MurderS[killcount[victimname]];//杀手的击杀积分=自己的积分加上被杀的人的杀人数目对应的积分
                           else killscore[killname]=MurderS[killcount[victimname]];
                       }
                       else killscore[killname]+=0;
               playerScores.insert(pair<string,int>(victimname,killscore[victimname]+RankS[Q-i] + t*A + B));
           }
           if(i==Q-1-1)playerScores.insert(pair<string,int>(killname,killscore[killname]+RankS[1] + t*A + B));
        }

        for(it=playerScores.begin();it!=playerScores.end();++it){
            cout<<it->first<<" "<<it->second<<endl;
        }
        playerScores.erase(playerScores.begin(),playerScores.end());
    }
    return 0;
}
