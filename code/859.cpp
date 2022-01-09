#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s == goal) {
            bool exist[26] = {0};
            for (auto ch: s) {
                if (exist[ch - 'a']) {
                    return true;
                } else {
                    exist[ch - 'a'] = true;
                }
            }
            return false;
        } else {
            int lenS = s.length(), lenG = goal.length();
            if (lenS != lenG) {
                return false;
            }
            int cnt = 0;
            char s1 = '0', g1 = '0', s2 = '0', g2 = '0';
            for (int i = 0; i < lenS; i++) {
                if (s[i] != goal[i]) {
                    if (++cnt >= 3) {
                        return false;
                    } else if (cnt == 1) {
                        s1 = s[i];
                        g1 = goal[i];
                    } else {
                        s2 = s[i];
                        g2 = goal[i];
                    }
                }
            }
            if (cnt == 2 && s1 == g2 && s2 == g1) {
                return true;
            }
            return false;
        }
    }
};