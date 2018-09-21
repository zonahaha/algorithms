#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class text_processor {
public :
    std::string process(const std::string &text, unsigned long width);
};

string itos(int i) // 将int 转换成string 
{
    stringstream s;
    s << i;
    return s.str();
}

string text_processor::process(const std::string &text, unsigned long width) {
    string res;
    int count = 0;
    int row = 1;
    int start;
    int length;
    if (width < 10 || width > 80)return "ERROR: Width out of range!";
    for (int i = 0; i < text.size();) {
        if (isalpha(text[i]) || text[i] == ' ') {
            if (isalpha(text[i])) {
                start=i;
                while (isalpha(text[i])) {
                    res += text[i++];
                    count++;
                }
                length=count-start;
                if (row == count / width + 1) {
                    res += '(';
                    res += itos(row);
                    res += ')';
                    res += ';';
                }
                else {
                    res += '(';
                    res += itos(row=(count-length)/width+1);
                    res += ',';
                    res += itos(row = count / width + 1);
                    res += ')';
                    res += ';';
                }
            } else {
                while (text[i] == ' ') {
                    res += text[i++];
                    count++;
                }
                if (row < count / width + 1) {
                    res += '(';
                    res += itos(row);
                    res += ')';
                    res += ';';
                }
                else {
                    res += '(';
                    res += itos(row=(count-length)/width+1);
                    res += ',';
                    res += itos(row = count / width + 1);
                    res += ')';
                    res += ';';
                }
            }
        } else return "ERROR: Invalid character detected!";
    }
    //for (int i = 0; i < res.size(); i++)cout << res[i];
   // cout << endl << endl;
    return res;
}

int main() {
    string test1 = "The main theme of education in engineering school is learning to teach yourself";
    string test2 = "So   many whitespaces";
    string test3 = "jifd jfiemfkd jfie ifekf fmdkjfim kofe l lkfoe lkoelkd lke mflmldkf mflefmle lkfoe ofmdlfkoe jifd jfiemfkd jfie ifekf fmdkjfim kofe l lkfoe lkoelkd lke mflmldkf mflefmle lkfoe ofmdlfkoe jifd jfiemfkd jfie ifekf fmdkjfim kofe l lkfoe lkoelkd lke mflmldkf mflefmle lkfoe ofmdlfkoe jifd jfiemfkd jfie ifekf fmdkjfim kofe l lkfoe lkoelkd lke mflmldkf mflefmle lkfoe ofmdlfkoe";
    string test4 = "jfie,feokfodkof,kfoekfkdf";
    text_processor test;
    test.process(test1, 30);
    test.process(test2, 10);
    cout << test3.size() << endl;
    test.process(test3, 10);
    test.process(test4, 20);
    test.process(test1, 5);
}
