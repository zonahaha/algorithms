#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>> t;

    int N, M;
    while(t--) {
        cin>> N >> M;

        int ret = 0;
        for(int i = 0; i < N; ++ i) {
            for(int j = 0; j < M; ++ j) {
                int change = 1;
                if(i - 1 >= 0) {
                    ++ change;
                    if(j - 1 >= 0) ++ change;
                    if(j + 1 < M) ++ change;
                }
                if(j - 1 >= 0)
                    ++ change;
                if(j + 1 < M)
                    ++ change;
                if(i + 1 < N) {
                    ++ change;
                    if(j - 1 >= 0) ++ change;
                    if(j + 1 < M) ++ change;
                }
                if(change % 2) ++ ret;
            }
        }

        cout<< ret <<endl;
    }
}
