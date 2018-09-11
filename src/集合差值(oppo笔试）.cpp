#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> N;


    int n = 0;
    int num=0;cin>>n;
    while (n--) {
        cin>>num;
        N.push_back(num);
    }
    int size = N.size();
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < size; i++) {
         for(int j=i+1;j<size;j++){
             A.push_back(N[i]+N[j]);
             B.push_back(N[i]-N[j]>0?N[i]-N[j]:N[j]-N[i]);
         }
    }
    sort(A.begin(),A.end());
    A.erease(Unique(A.begin(),A.end()),A.end());
    sort(B.begin(),B.end());
    B.erease(Unique(B.begin(),B.end()),B.end());
    int lenA=A.size();
    int lenB=B.size();
    vector<int> D;
    for(int i=0;i<lenA;i++){
        for(int j=0;j<lenB;j++){
            D.push_back(A[i]-B[j]>0?A[i]-B[j]:B[j]-A[i]);
        }
    }
    sort(D.begin(),D.end());
    D.erease(Unique(D.begin(),D.end()),D.end());
    int res=D[0]+D[D.size()-1]+D.size();
    cout<<res;
}
