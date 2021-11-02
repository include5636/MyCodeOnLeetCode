#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int line[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> ans;
        for (auto & word: words) {
            int len = word.length();
            bool isOneLine = 1;
            for (int i = 1; i < len; i++) {
                if (line[tolower(word[i]) - 'a'] != line[tolower(word[i - 1]) - 'a']) {
                    isOneLine = 0;
                    break;
                }
            }
            if (isOneLine) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};