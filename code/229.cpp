#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> exist;
        int size = nums.size(), times = size / 3;
        vector<int> ans;
        for (int num: nums) {
            if (exist[num] == times) {
                ans.emplace_back(num);
            }
            exist[num]++;
        }
        return ans;
    }
};