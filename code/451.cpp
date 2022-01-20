#include<bits/stdc++.h>
using namespace std;

/**
 * 先统计各字符出现的次数
 * 再进行堆排序，依次pop
 */

class Solution {
public:
    struct cmp {
        bool operator()(pair<char, int> x, pair<char, int> y) {
            return x.second < y.second;
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char & c: s) {
            freq[c]++;
        }

        string ans = "";
        priority_queue<pair<char, int>, vector<pair<char, int> >, cmp> q;
        for (auto & item: freq) {
            q.push(make_pair(item.first, item.second));
        }

        while (q.size() != 0) {
            ans.append(q.top().second, q.top().first);
            q.pop();
        }   
        return ans;
    }
};