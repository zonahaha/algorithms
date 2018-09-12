#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int N = 100000;
long long n;
long long a;
long long b;
long long c;

long long gcd(long long a, long long b) {//判断是否互质，可以学习一下啊
    return b == 0 ? a : gcd(b, a % b);
}

long long gougushu(long long &i, long long &j) {//勾股数满足这样的关系
    a = j * j - i * i;
    b = 2 * i * j;
    c = i * i + j * j;
    return c;
}

int main() {
    cin >> n;
    int count = 0;
    vector<long long> v(n, 0);
    long long m = sqrt(n + 0.5);
    for (long long i = 1; i <= m; i++) {
        for (long long j = i + 1; j <= m; j += 2) {
            if (gcd(j, i) == 1) {
                c = gougushu(i, j);
                if (c <= n) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}
