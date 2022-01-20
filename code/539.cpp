#include<bits/stdc++.h>
using namespace std;

/*
main idea: 将时间列表中的时间(string)转为以分钟表示的时间(int)，并存进优先队列中。
遍历优先队列，最小时间差必定在相邻时间点之间。
注意处理corner case：["23：59","00:00"]的时间差是 1，不是1439.
我是直接把所有时间点 +1 day(1440 min) 的时间也push进优先队列，事实上不需要这样，之要最后单独判断一下优先队列的头尾元素即可。
*/

class Solution {
public:
    int calcTime(string s) {
        return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        priority_queue<int> q;
        for (auto & s: timePoints) {
            q.push(calcTime(s));
            q.push(calcTime(s) + 1440);
        }
        int pre = q.top(), minInterval = INT_MAX;
        q.pop();
        while (!q.empty()) {
            minInterval = min(minInterval, pre - q.top());
            if (minInterval == 0) {
                return minInterval;
            }
            pre = q.top();
            q.pop();
        }
        return minInterval;
    }
};