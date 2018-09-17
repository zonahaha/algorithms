#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int triangle(vector<int> &nums,int start,int end){
    for(int i=start;i<=end;i++){
        for(int j=i+1;j<=end;j++){
            for(int k=j+1;k<=end;k++){
                if(nums[i]+nums[j]>nums[k]&&abs(nums[i]-nums[j])<nums[k]){
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                    return k;
                }
            }
        }
    }
    return NULL;
}
bool rectangle(vector<int> &nums,int start,int end){//目前只想到判断四边形和三角形的情况了，毕竟没有运行过
    sort(nums.begin(),nums.begin()+end);
    int count=0;
    vector<int> rec;
    for(int i=0;i<end;i++){
        if(nums[i]==nums[i+1]){
            count++;
            rec.push_back(nums[i]);
            i++;
        }
        if(count>=2){
            cout<<nums[0]<<" "<<nums[1]<<" "<<endl;
            break;
        }
    }
    return count>=2?end:0;

}
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    int num;
    while(n--){
        cin>>num;
        nums.push_back(num);
    }
    int res=0;
    for(int i=2;i<nums.size();i++){
        if(triangle(nums,0,i)){
            cout<<triangle(nums,0,i)+1;
            return 0;
        }
        if(rectangle(nums,0,i)){
            cout<<rectangle(nums,0,i);
            return 0;
        }

    }
}
