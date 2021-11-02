#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> exist;
        for (int num: nums) {
            if (exist[num]) {
                return num;
            } else {
                ++exist[num];
            }
        }
        return 0;
    }
};