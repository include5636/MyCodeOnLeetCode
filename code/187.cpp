#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int len = s.length();
        if (len >= 11) {
            unordered_map<string, int> exist;
            for (int i = 10; i <= len; i++) {
                exist[s.substr(i - 10, 10)]++;
                if(exist[s.substr(i - 10, 10)] == 2) 
                    ans.push_back(s.substr(i - 10, 10));
            }
        }
        return ans;
    }
};