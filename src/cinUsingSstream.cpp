#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    vector<int> nums;
    string s;
    getline(cin,s);
    stringstream stringin(s);
    int n=0;
    while(stringin>>n){
        nums.push_back(n);
    }
    return 0;
}
