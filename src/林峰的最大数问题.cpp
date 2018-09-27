#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
///////////////////////////题目是输入n个非负整数，求能形成的最大树，林峰写的
int main()
{
    ll n;
    cin>> n;

    vector<ll> arr(n, 0);
    for(ll i = 0; i < n; ++ i)
        cin>> arr[i];

    sort(arr.begin(), arr.end(), [](ll a, ll b) {
        return to_string(a) + to_string(b) >= to_string(b) + to_string(a); });////////这里排序感觉挺巧的，直接用字符串比较大大小，秒啊，
                                                                              ////////还有to_string函数也用的好,字符串转数字stoi,stoll，
                                                                              ////////////把字符串中的数字转数字"worjie 98jfekf"得到98

    string ret = "";
    for(auto num : arr)
        ret += to_string(num);
    if(ret[0]=='0')cout<<"0"<<endl;
    else cout<< ret <<endl;
}
