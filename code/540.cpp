#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1; 
            if ((mid == 0 && nums[mid] != nums[mid + 1]) || (mid > 0 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])) {
                return nums[mid];
            } else if (nums[mid] != nums[mid + 1]) {
                if ((mid - 1) & 1) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (mid & 1) {
                    r = mid;
                } else {
                    l = mid + 2;
                }
            }
        }
        return nums[l];
    }
};