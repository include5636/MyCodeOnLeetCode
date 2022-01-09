#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findAnsOdd(vector<int>& nums1, vector<int>& nums2, int pos1, int pos2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (pos1 == size1) {
            return nums2[pos2];
        } else if (pos2 == size2) {
            return nums1[pos1];
        } else {
            return min(nums1[pos1], nums2[pos2]);
        }
    }

    double findAnsEven(vector<int>& nums1, vector<int>& nums2, int pos1, int pos2) {
        int size1 = nums1.size(), size2 = nums2.size();
        double res = 0;
        for (int i = 0; i < 2; ++i) {
            if (pos1 == size1) {
                res += nums2[pos2++];
            } else if (pos2 == size2) {
                res += nums1[pos1++];
            } else {
                if (nums1[pos1] < nums2[pos2]) {
                    res += nums1[pos1++];
                } else {
                    res += nums2[pos2++];
                }
            }
        }
        return res / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 == 0) {
            if(size2 & 1) {
                return nums2[size2 >> 1];
            } else {
                return ((double)nums2[size2 >> 1] + (double)nums2[(size2 >> 1) - 1]) / 2;
            }
        } else if (size2 == 0) {
            if(size1 & 1) {
                return nums1[size1 >> 1];
            } else {
                return ((double)nums1[size1 >> 1] + (double)nums1[(size1 >> 1) - 1]) / 2;
            }
        } else if (size1 == 1 && size2 == 1) {
            return ((double)nums1[0] + (double)nums2[0]) / 2;
        }
        int l1 = 0, r1 = size1 - 1, l2 = 0, r2 = size2 - 1, tar = (size1 + size2 + 1) >> 1;
        while(l1 < r1 || l2 < r2) {
            int mid1 = (l1 + r1 + 1) >> 1, mid2 = (l2 + r2 + 1) >> 1;
            if (mid1 + mid2 + 2 > tar) {
                if (nums1[mid1] < nums2[mid2]) {
                    if (l2 != r2) {
                        r2 = mid2 - 1;
                    } else {
                        r1 = mid1 - 1;
                    }
                } else {
                    if (l1 != r1) {
                        r1 = mid1 - 1;
                    } else {
                        r2 = mid2 - 1;
                    }
                }
            } else {
                if (nums1[mid1] < nums2[mid2]) {
                    if (l1 != r1) {
                        l1 = mid1;
                    } else {
                        l2 = mid2;
                    }
                } else {
                    if (l2 != r2) {
                        l2 = mid2;
                    } else {
                        l1 = mid1;
                    }
                }
            }
        }
        // cout <<"l1 = "<<l1<<endl<<"l2 = "<<l2<<endl;
        if ((size1 + size2) & 1) {
            if (nums1[l1] < nums2[l2]) {
                return findAnsOdd(nums1, nums2, l1 + 1, l2);
            } else {
                return findAnsOdd(nums1, nums2, l1, l2 + 1);
            }
        } else {
            if (nums1[l1] < nums2[l2]) {
                return findAnsEven(nums1, nums2, l1 + 1, l2);
            } else {
                return findAnsEven(nums1, nums2, l1, l2 + 1);
            }
        }
    }
};