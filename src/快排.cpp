#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void swap2(vector<int> &nums, int &a, int &b) {
    int temp;
    temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int part(vector<int> &nums, int start, int end) {
    int i = nums[start];////////////这里不要乱写
    while (start < end) {
        while (start < end && i <= nums[end])
            end--;
        swap2(nums, start, end);
        while (start < end && i >= nums[start])
            start++;
        swap2(nums, start, end);
    }
    return start;
}

void sort(vector<int> &nums, int start, int end) {
    if (start < end) {
        int i = part(nums, start, end);
        sort(nums, start, i-1 );////还有这里，i-1,i+1
        sort(nums, i+1 , end);
    }
}

int main() {
    vector<int> nums = {1, 9, 7, 5, 0, 3, 3};
    sort(nums, 0, nums.size()-1 );
    for (auto i:nums)cout << i << " ";

}
