#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > nums[0]) {
                l = mid; 
            } else {
                r = mid - 1;
            }
        }
        if (l != nums.size() - 1) {
            return nums[l + 1];
        } else {
            return nums[0];
        }
    }
};