#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long r = (long long)sqrt(c), l = 0;
        while(l <= r) {
            long long tmp = l * l + r * r;
            if (tmp == c) {
                return true;
            } else if (tmp < c) {
                l++;
            } else {
                r--;
            }
        }
        return 0;
    }
};