#include<iostream>
#include<ctime>
#include <vector>
#include <sstream>

using namespace std;

void print(vector<int> &heap)
{
    for(auto i:heap){
        cout<<i<<endl;
    }
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void max_heapify(vector<int> &heap, int cur)
{
    int left=cur*2+1;//左儿子节点
    int right=cur*2+2;//右儿子节点
    int size=heap.size();
    int max=cur;
    if(left<size&&heap[left]>heap[cur])max=left;
    if(right<size&&heap[right]>heap[max])max=right;
    swap(heap[max],heap[cur]);
    if(max!=cur)max_heapify(heap,max);//找到最大的节点，交换,递归
}

void bulid_max_heap(vector<int> &heap)
{
    for(int i=heap.size()/2-1;i>=0;i--){//从最后一个非叶子节点开始，向上，叶子节点不用max_heapify
        max_heapify(heap,i);
    }
}

int main()
{
    vector<int> heap;
    string in;
    int n;
    getline(cin,in);
    stringstream stringin(in);//用sstream处理未知个数的输入
    while(stringin>>n){
         heap.push_back(n);
    }
    bulid_max_heap(heap);
    cout << "-------------" << endl;
    print(heap);//输出
    return 0;
}
