#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        int elements[2], cnt[2] = {0, 0};
        for (auto & num: nums) {
            if (cnt[0] > 0 && num == elements[0]) {
                cnt[0]++;
            } else if (cnt[1] > 0 && num == elements[1]) {
                cnt[1]++;
            } else if (cnt[0] == 0) {
                elements[0] = num;
                cnt[0]++;
            } else if (cnt[1] == 0) {
                elements[1] = num;
                cnt[1]++;
            } else {
                cnt[0]--;
                cnt[1]--;
            }
        }
        //check
        cnt[0] = 0;
        cnt[1] = 0;
        for (auto & num: nums) {
            if (num == elements[0]) {
                cnt[0]++;
            } else if (num == elements[1]) {
                cnt[1]++;
            }
        }
        if (cnt[0] > size / 3) {
            ans.emplace_back(elements[0]);
        }
        if (cnt[1] > size / 3) {
            ans.emplace_back(elements[1]);
        }
        return ans;
    }
};