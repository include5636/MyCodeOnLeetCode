#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calc1(char s)
    {
        if (s == '0')
            return 0;
        else if (s == '*')
            return 9;
        else
            return 1;
    }

    long long calc2(char s, char t)
    {
        if (t == '0')
            return 0;
        else if (t == '1')
        {
            if (s == '*')
                return 9;
            else
                return 1;
        }
        else if (t == '2')
        {
            if (s == '*')
                return 6;
            else if (s <= '6')
                return 1;
            else
                return 0;
        }
        else if (t == '*')
        {
            if (s == '*')
                return 15;
            else if (s <= '6')
                return 2;
            else
                return 1;
        }
        else
            return 0;
    }

    int numDecodings(string s)
    {
        long long pre2 = 1, pre1 = calc1(s[0]), cur = calc1(s[0]);
        int len = s.size();
        for (int i = 1; i < len; i++)
        {
            cur = (pre2 * calc2(s[i], s[i-1]) + pre1 * calc1(s[i])) % 1000000007;
            pre2 = pre1;
            pre1 = cur;
        }
        return (int)cur;
    }
};