#include<bits/stdc++.h>
using namespace std;

/**
 * main idea: 滑动窗口，右边界遇到已存在的元素就先记录当前长度并打擂，之后不断地将左边界右移并删去元素，直到遇到这个存在的元素。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> exist;
        int len = s.length(), posL = 0, maxLen = 0;
        for (int i = 0; i < len; i++) {
            if(!exist[s[i]]) {
                exist[s[i]] = 1;
            } else {
                maxLen = max(maxLen, i - posL);
                while (s[posL] != s[i] && posL < i) {
                    exist[s[posL++]] = 0;
                }
                posL++;
            }
        }
        maxLen = max(maxLen, len - posL);
        return maxLen;
    }
};