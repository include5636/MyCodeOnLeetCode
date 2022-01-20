#include<bits/stdc++.h>
using namespace std;

/**
 * 桶，记录 1 和 2 的数量。
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num1 = 0, num2 = 0, pos = 0, len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                nums[pos++] = 0;
            } else if (nums[i] == 1) {
                num1++;
            } else {
                num2++;
            }
        }
        while (num1--) {
            nums[pos++] = 1;
        }
        while (num2--) {
            nums[pos++] = 2;
        }
    }
};