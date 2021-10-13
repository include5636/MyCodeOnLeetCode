#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int tip1 = 0, tip2 = 0;
        while (tip1 < m && tip2 < n) {
            if (nums1[tip1] <= nums2[tip2]) {
                tmp.emplace_back(nums1[tip1++]);
            } else {
                tmp.emplace_back(nums2[tip2++]);
            }
        }
        while (tip1 < m) {
            tmp.emplace_back(nums1[tip1++]);
        }
        while (tip2 < n) {
            tmp.emplace_back(nums2[tip2++]);
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = tmp[i];
        }
    }
};