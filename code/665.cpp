#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        nums.emplace(nums.begin(), -1000000);
        nums.emplace_back(1000000);
        bool chance = 1;
        int size = nums.size();
        for (int i = 1; i < size - 1; i++) {
            if (nums[i] < nums[i - 1] && nums[i] > nums[i + 1]) {
                return 0;
            } else if (nums[i] >= nums[i - 1] && nums[i] <= nums[i + 1]) {
                continue;
            } else if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1]) {
                if (!chance)
                    return 0;
                chance = 0;
                if (nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            } else if (nums[i] <= nums[i - 1] && nums[i] <= nums[i + 1]) {
                if (!chance)
                    return 0;
                chance = 0;
                if (nums[i - 1] > nums[i + 1] && nums[i - 2] > nums[i]) {
                    return 0;
                } else if (nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return 1;
    }
};