#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> val;
    int subarraySum(vector<int>& nums, int k) {
        val[0] = 1;
        int size = nums.size(), ans = 0;
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            ans += val[sum - k];
            val[sum]++;
        }
        return ans;
    }
};