#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = 46341;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (mid * mid > num) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if (l * l == num) {
            return true;
        } else {
            return false;
        }
    }
};