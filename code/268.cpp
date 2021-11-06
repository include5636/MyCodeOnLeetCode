#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> exist;
        int size = nums.size();
        for (int num: nums) {
            exist[num] = true;
        }
        for (int i = 0; i <= size; i++) {
            if (!exist[i]) {
                return i;
            }
        }
        return -1;
    }
};