#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int need[100] = {0}, diffNum = 0;
        bool exist[100] = {0};
        int lenT = t.length(), lenS = s.length();
        for (int i= 0; i < lenT; i++) {
            if (!need[t[i] - 'A']) {
                diffNum++;
            }
            need[t[i] - 'A']++;
            exist[t[i] - 'A'] = 1;
        }
        int l = 0, ansL = 0, ansR = -1, minLen = 1000000;
        for (int r = 0; r < lenS; r++) {
            if (exist[s[r] - 'A']) {
                need[s[r] - 'A']--;
                if(need[s[r] - 'A'] == 0) {
                    diffNum--;
                }
            }
            while (need[s[l] - 'A'] <= 0 && l < r) {
                if (!exist[s[l] - 'A']) {
                    l++;
                } else if (need[s[l] - 'A'] < 0) {
                    need[s[l] - 'A']++;
                    l++;
                } else {
                    break;
                }
            }
            if (!diffNum && (r - l + 1 < minLen)) {
                minLen = r - l + 1;
                ansL = l;
                ansR = r;
            }
        }
        return s.substr(ansL, ansR - ansL + 1);
    }
};