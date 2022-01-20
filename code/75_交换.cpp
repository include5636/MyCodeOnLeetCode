#include<bits/stdc++.h>
using namespace std;

/**
 * "0，1，2 排序。一次遍历，如果是0，则移动到表头，如果是2，则移动到表尾，不用考虑1。0和2处理完，1还会有错吗？" --- Dong_Wu
 * @Source: https://leetcode-cn.com/problems/sort-colors/comments/
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr1 = 0, ptr2 = nums.size() - 1;
        for (int i = 0; i <= ptr2; i++) {
            while (nums[i] == 2 && i <= ptr2) {
                swap(nums[ptr2--], nums[i]);
            }
            if (nums[i] == 0) {
                swap(nums[ptr1++], nums[i]);
            }
        }
    }
};