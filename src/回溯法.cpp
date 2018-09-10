#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

bool hasPathCore(const char *matrix, int row, int rows, int col, int cols, const char *str, int &pathLength, bool *visited) {
    bool haspath = false;
    if(str[pathLength]=='\0'){
       // cout<<"end "<<endl;
        return true;
    }
//cout<<"str[pathlength]= "<<str[pathLength]<<" length= "<<pathLength<<endl;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col]) {
        visited[row * cols + col] = true;
        ++pathLength;
        haspath = hasPathCore(matrix, row - 1, rows, col, cols, str, pathLength, visited) ||
                  hasPathCore(matrix, row + 1, rows, col, cols, str, pathLength, visited) ||
                  hasPathCore(matrix, row, rows, col - 1, cols, str, pathLength, visited) ||
                  hasPathCore(matrix, row, rows, col + 1, cols, str, pathLength, visited);
        if (!haspath) {
            --pathLength;
            visited[row * cols + col] = false;
        }
       // else cout<<"happath==true char: "<<matrix[row*cols+row]<<endl;

    }
    return haspath;
}

bool hasPath(const char *matrix, int rows, int cols, const char *str) {
    bool *visited = new bool[rows * cols];
    memset(visited, false, rows * cols);
    int pathLength = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (hasPathCore(matrix, i, rows, j, cols, str, pathLength, visited)) {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main() {
    char *matrix = "abtgcfcsjdeh";
    char *str = new char;
    cin >> str;
    bool res = hasPath(matrix, 4, 4, str);
    cout << "res=: " << res;
    return res;
}
