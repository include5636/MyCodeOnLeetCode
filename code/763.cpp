#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int end[26] = {0}, size = s.size();
        for (int i = 0; i < size; i++)
                end[s[i] - 'a'] = i + 1;
        int last = end[s[0] - 'a'], first = 1;
        vector<int> ans;
        for (int i = 0; i < size; i++)
            if (i + 1 == last) {
                ans.push_back(last - first + 1);
                if (i < size - 1) {
                    first = i + 2;
                    last = end[s[i + 1] - 'a'];
                }
            } else if (i + 1 < last && end[s[i] - 'a'] > last)
                last = end[s[i] - 'a'];
        return ans;
    }
};