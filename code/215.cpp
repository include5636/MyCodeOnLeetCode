#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto & num: nums) {
            q.push(num);
        }
        for (int i = 1; i < k; i++) {
            q.pop();
        }
        return q.top();
    }
};