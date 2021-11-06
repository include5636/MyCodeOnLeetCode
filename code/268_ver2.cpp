#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size(), ans = 0;
        for (int i = 0; i < size; i++) {
            ans ^= nums[i] ^ i;
        }
        return ans ^ size;
    }
};