#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tip1 = m - 1, tip2 = n - 1, tip3 = m + n - 1;
        while (tip1 >=0 && tip2 >=0) {
            if (nums1[tip1] > nums2[tip2]) {
                nums1[tip3--] = nums1[tip1--];
            } else {
                nums1[tip3--] = nums2[tip2--];
            }
        }
        while (tip1 >= 0) {
            nums1[tip3--] = nums1[tip1--];
        }
        while (tip2 >= 0) {
            nums1[tip3--] = nums2[tip2--];
        }
    }
};