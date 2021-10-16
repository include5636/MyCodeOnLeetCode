#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0, len = s.length();
        for (int i = 0; i < len; i++)
            if(s[i] != '-')
            {
                cnt++;
                if(s[i] <='z' && s[i] >= 'a')
                    s[i] = s[i] - 'a' + 'A';
            }
        int first= cnt % k, pos = 0;
        string ans = "";
        for(int i = 0; i < len; i++)
            if(s[i] != '-')
            {
                ans += s[i];
                pos++;
                if(pos == k || pos == first)
                {
                    if(pos == first)
                        first = 10000000;
                    ans += '-';
                    pos = 0;
                }
            }
        return ans.substr(0, ans.length() - 1);
    }
};