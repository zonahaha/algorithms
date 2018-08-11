#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void help(vector<int> &a, int &i, int k, vector<pair<int, int>> &operations) {
    if(i == k) {
        return;
    }

    pair<int, int> tallest, shortest;
    tallest.first = 0;
    shortest.first = 10001;

    for(auto i = 0; i < a.size(); ++ i) {
        if(a[i] > tallest.first) {
            tallest.first = a[i];
            tallest.second = i;
        }
        if(a[i] < shortest.first) {
            shortest.first = a[i];
            shortest.second = i;
        }
    }
    pair<int, int> operation;
    operation.first = tallest.second + 1;
    operation.second = shortest.second + 1;
    operations.push_back(operation);

    -- a[tallest.second];
    ++ a[shortest.second];

    int maxH = 0, minH = 10001;
    for(auto h : a) {
        if(h > maxH)
            maxH = h;
        if(h < minH)
            minH = h;
    }
    if(abs(maxH - minH) <= 1) return;

    ++ i;
    help(a, i, k, operations);
}

int main() {
    int n, k;
    cin>> n >> k;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++ i)
        cin>> a[i];

    vector<pair<int, int>> operations;

    int i = 0, maxH = 0, minH = 10001;
    help(a, i, k, operations);

    for(auto h : a) {
        if(h > maxH)
            maxH = h;
        if(h < minH)
            minH = h;
    }

    cout<< abs(maxH - minH) << " " << i + 1 <<endl;
    for(auto operation : operations)
        cout<< operation.first <<" "<< operation.second <<endl;
}
