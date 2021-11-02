#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> times;
        vector<int> ans;
        for (int & num: nums) {
            times[num]++;
        }
        for (int & num: nums) {
            if (times[num] == 1) {
                ans.emplace_back(num);
            }
        }
        return ans;
    }
};