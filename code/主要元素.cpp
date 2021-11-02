#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element, cnt = 0;
        for (auto & num: nums) {
            if (cnt > 0 && num == element) {
                cnt++;
            } else if (cnt > 0) {
                cnt--;
            } else {
                element = num;
                cnt++;
            }
        }
        cnt = 0;
        for (auto & num: nums) {
            if (num == element) {
                cnt++;
            }
        }
        // cout<<"cnt = "<<cnt<<endl<<"element = "<<element;
        if (cnt > (nums.size() >> 1)) {
            return element;
        } else {
            return -1;
        }
    }
};