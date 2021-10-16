#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cur = "", pre = "1";
        while (--n) {
            int pos = 0, cnt = 1, len = pre.size();
            char nowCh;
            while (pos < len) {
                nowCh = pre[pos];
                while (pos < len && pre[pos + 1] == nowCh) {
                    cnt++;
                    pos++;
                }
                cur.push_back((char)(cnt + '0'));
                cur.push_back(nowCh);
                pos++;
                cnt = 1;
            }
            pre = cur;
            cur = "";
        }
        return pre;
    }
};