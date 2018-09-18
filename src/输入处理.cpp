#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string in;
    string ss;
    vector<string> strings;
    string end="";
    while(getline(cin,in)){//用于输入未知行数的情况
        if(in==end)break;//用来判断是否结束输入
        istringstream s(in);
        while(s>>ss){//用于根据空格将一行分解成多个字符串存入到vector中，第一种方法，直接istringstream只分割空格
            strings.push_back(ss);
        }
        for(auto i:strings)cout<<i<<endl;
        strings.clear();
    }
}
///////////////////////////////////////////////////第二种方法，用split只分割一个字符
vector<string> split(string &s,char token){//或者用split函数，把token定义成空格字符，逗号，中括号啥的都可以,适合一个分隔符char
    istringstream ss(s);
    vector<string> res;
    string temp;
    while(getline(ss,temp,token))res.push_back(temp);
    for(auto i:res)cout<<i<<endl;
    return res;
}
/////////////////////////////////////////////////////第三种方法，用strtok，可分割多种字符
vector<string> strtok2(char* arr,char* token){//但是这种方法的缺点是输入是字符数组的形式，下面写了主函数调用例子,适合多个分隔符
    char *p;//这里不可变
    p = strtok(arr,token);//注意这里和下面那个null的区别
    vector<string> res;
    while(p != NULL)
    {
        res.push_back(p);
        p=strtok(NULL, token);//返回从str开始被分隔符分割的字符串，没有的话返回null
    }
    return res;
}
int main(){
    char* arr;
    while(gets(arr)){
        if(arr==end)break;//也是用来判断输入结束
        vector<string> strtokReturn;
        strtokReturn=strtok2(arr,",[] ");//不会主动分辨空格，所以要把所有分割符都写进去，每个元素都会是一个分割符
        for(auto i:strtokReturn)cout<<i<<endl;
        strtokReturn.clear();
    }
}
