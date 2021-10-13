#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[1] < b[1];});
        int size = intervals.size(), ans = 0, bound = intervals[0][1];
        for (int i = 1; i < size; i++) 
            if(intervals[i][0] >= bound) 
                bound = intervals[i][1];
            else
                ans++;
        return ans;
    }
};