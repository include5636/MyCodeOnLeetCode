#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool areNumbersAscending(string s) {
        int len = s.length(), pre = -1, cur = 0;
        bool fl = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i] - '0';
                fl = 1;
            } else if(s[i] == ' ' && s[i - 1] >= '0' && s[i - 1] <= '9') {
                if (cur <= pre) {
                    return 0;
                } else {
                    pre = cur;
                    cur = 0;
                }
                fl = 0;
            } else {
                fl = 0;
            }
        }
        if (fl && cur <= pre) {
            return 0;
        } else {
            return true;
        }
    }
};