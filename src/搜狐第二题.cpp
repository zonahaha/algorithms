class Solution {
public:
    int reachNumber(int target) {
        target=target>0?target:-target;
        for (int i = 1;; i++) {
            while(i*(i+1)<2*target)i++;//全正数都小于target那肯定不够，所以排除
            int x2 = (i * (i + 1) / 2 + target);
            if (x2 % 2 == 0){//x 是个正
                int y = x2 / 2 - target;
                if (x2 / 2 + y == i * (i + 1) / 2)
                    return i;
            }
        }
    }
};
///////////////////////题目是：从原点出发，只能向左或者向右走与次数相等的距离，比如3=1+2，4=-1+2+3，5=1-2-3+4+5转化成数学问题
///////////////////////大佬的思路：1+...i的和为i(1+i)/2 分成X Y两部分，X + Y = i(1+i)/2;X-Y=target;
////////////////////////两个等式相加,2X=i(i+1)/2+target;所以问题转化成找到满足x是个正整数的i值，即可
