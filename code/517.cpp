#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMinMoves(vector<int> &machines)
    {
        int sum = 0;
        for (int i : machines)
            sum += i;
        if (sum %  machines.size())
            return -1;
        int ans = 0, curSum = 0, num = sum / machines.size();
        for (int i : machines)
        {
            curSum += i - num;
            if(ans < i - num)
                ans = i - num;
            if(ans < abs(curSum))
                ans = abs(curSum);
        }
        return ans;
    }
};