#include<bits/stdc++.h>
using namespace std;

/* 先找出最大值，之后再遍历判断 */

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int nSize = nums.size(), maxPos = 0;
        for (int i = 1; i < nSize; i++) {
            if (nums[i] > nums[maxPos]) {
                maxPos = i;
            }
        }
        for (int i = 0; i < nSize; i++) {
            if (nums[maxPos] < (nums[i] << 1) && i != maxPos) {
                return -1;
            }
        }
        return maxPos;
    }
};