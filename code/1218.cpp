#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0, len[20005] = {0};
        for (int num: arr) {
            if (num - difference + 10000 < 0 || num - difference + 10000 > 20000) {
                len[num + 10000] = 1;
            } else {
                len[num + 10000] = len[num + 10000 - difference] + 1;
                if (len[num + 10000] > ans) {
                    ans = len[num + 10000];
                }
            }
        }
        return ans;
    }
};