#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swapNum(vector<int> &nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
    }

    int depart(vector<int>& nums, int left, int right) {
        swapNum(nums, left, (left + right) >> 1);
        int i = left + 1, j = right;
        while (true) {
            while (i < right && nums[i] <= nums[left]) {
                ++i;
            }
            while (j > left && nums[j] >= nums[left]) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swapNum(nums, i, j);
        }
        swapNum(nums, left, j);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, tar = nums.size() - k;
        while (left < right) {
            int pivot = depart(nums, left, right);
            cout<<"pivot = "<<pivot<<endl;
            for (int num: nums) {
                    cout<<num<<' ';
                }
            if (pivot == tar) {
                return nums[pivot];
            } else if (pivot < tar) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return nums[left];
    }
};