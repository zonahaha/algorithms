#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string &s, char token) {//重点是这里的字符串分割函数 用空格分割成多个字符串
    istringstream iss(s);
    vector<string> v;
    string str;
    while (getline(iss, str, token))v.push_back(str);
    return v;
}

struct stu {
    string name;
    int avg;
};

int main() {
    string s;
    vector<stu> students;
    int i = 0;
    int n = 5;
    while (getline(cin, s)) {
        string eof = "";
        if (eof == s)break;
        vector<string> res;
        res = split(s, ' ');
        stu stu1;
        stu1.name = res[0];
        int add = 0;
        for (int j = 1; j < res.size(); j++)add += stoll(res[j]);
        stu1.avg = add / (res.size() - 1);
        students.push_back(stu1);
    }
    sort(students.begin(), students.end(), []
            (stu &a, stu &b) {
        if (a.avg > b.avg)return true;
        else return false;
    });
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << students[i].avg << endl;
    }
}
