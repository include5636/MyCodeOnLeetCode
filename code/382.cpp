#include<bits/stdc++.h>
using namespace std;

/*
rand() 返回 [0, RAND_MAX] 之间的随机数
rand() / RAND_MAX 返回 [0，1] 之间的随机数.
*/

class Solution {
public:
    vector<int> a;

    Solution(ListNode* head) {
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return a[(int)(a.size() * rand() / RAND_MAX)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */