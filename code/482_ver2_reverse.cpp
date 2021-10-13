#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--) 
            if(s[i] != '-') {
                ans = char(toupper(s[i])) + ans;
                cnt++;
                if(cnt % k == 0) {
                    ans = '-' + ans;
                    cnt = 0;
                }
            }
        if(ans[0] == '-')
            return ans.substr(1, ans.length() - 1);
        else
            return ans;
    }
};