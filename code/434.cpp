#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        s = s + ' ';
        int len = s.length(), cnt = 0;
        for (int i = 1; i < len; i++)
            if(s[i] == ' ' && s[i - 1] != ' ')
                cnt++;
        return cnt;
    }
};