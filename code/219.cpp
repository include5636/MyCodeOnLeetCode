#include<bits/stdc++.h>
using namespace std;

/*
main idea: 滑动窗口，窗口长度为k。
遍历数组，
当 i > k 时，移除滑动窗口最前面的元素(nums[i - k - 1])，
之后判断准备加入滑动窗口的元素是否已存在，如果已存在则直接return true，
把该元素加入集合，继续循环
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};