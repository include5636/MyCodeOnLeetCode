#include<bits/stdc++.h>
using namespace std;

/*
main idea: （是后面补的，有点忘了当时怎么想的）
我们只关心 mod 3 后的结果，石子的实际数量并不关心。
首先对石子数量 mod 3，分别记录各结果的数量。
之后列举出所有的符合最佳决策的情况，分情况讨论。
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int size = stones.size(), zero = 0, one = 0, two = 0;
        for (int i: stones) {
            if(i % 3 == 0) {
                zero++;
            }
            else if(i % 3 == 1) {
                one++;
            }
            else two++;
        }
        if(one > two) 
            swap(one, two);
        if(one > 1) {
            two -= one - 1;
            one = 1;
        }
        if((one == 0) && (two == 0 || two == 1 || two == 2))
            return 0;
        else if(one == 0)
            return zero % 2;
        else if(one == 1 && two >= 4)
            return 1;
        else
            return 1 - zero % 2;
    }
};