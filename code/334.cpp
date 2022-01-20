#include<bits/stdc++.h>
using namespace std;

/**
 * 只要找到一个大于“历史次小值”的数就算成功。
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int MAX = 2147483647;
        int minValue = MAX, secondMin = MAX, tar = MAX;
        for (int & num: nums) {
            if (num > tar) {
                return true;
            } else if (num < minValue) {
                minValue = num;
                secondMin = MAX;
            } else if (num < secondMin && num != minValue) {
                secondMin = num;
                tar = min(tar, secondMin);
            }
        }
        return false;
    }
};