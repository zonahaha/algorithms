#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

typedef long long ll;
using namespace std;

char up(char& m){
    return m-32;
}
int main(){
    string s;
    getline(cin,s);
    ll i=0;
    map<int,ll> count;
    while(i<s.size()){
        if(isalpha(s[i])){
            if(isupper(s[i])){
                count[(int)s[i]-65]++;
            }
            else {
                count[(int)s[i]-97]++;
            }
        }
        i++;
    }
    vector<pair<int, ll>> vt;//这里用vector实现map的按值排序，先用pair插入到vector，在对vector用pair排序
    for (auto it = count.begin(); it != count.end(); it++)
        vt.push_back(make_pair(it->first, it->second));

    sort(vt.begin(), vt.end(),
         [](const pair<char, ll> &x, const pair<char, ll> &y){
             if(x.second > y.second)return true;
             else if(x.second < y.second)return true;
             else if(x.first>y.first)return false;
             else return true;
         });
    auto it=vt.begin();
        cout<<(char)(it->first+'A')<<it->second<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////林峰自己写的，，，我真是蠢
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    unordered_map<char, int> mp;
    int most = 0;
    char c = s[0];
    for(auto ch : s) {
        if(isalpha(ch)) {
            mp[toupper(ch)]++;
            if (most <= mp[toupper(ch)]) {
                most = mp[toupper(ch)];
                if(ch < c)
                    c = ch;
            }
        }
    }

    cout<< (char) toupper(c) << most <<endl;
}
