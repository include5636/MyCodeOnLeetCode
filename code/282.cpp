#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // clumsy
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        int len = num.length(), times = pow(4, len - 1);
        if (len == 1) {
            if (num[0] - '0' == target) {
                ans.emplace_back(num);
            }
            return ans;
        }
        // op == 0: null
        // op == 1: +
        // op == 2: -
        // op == 3: *
        vector<int> op(len, 0);
        while (times--) {
            // calc
            long long pre = 0, cur = num[0] - '0', sign = 1;
            for (int i = 0; i < len - 1; i++) {
                long long number = num[i + 1] - '0';
                if (op[i] == 0) {
                    if (cur == 0) {
                        pre = -10000000000;
                        break;
                    }
                    cur = cur * 10 + number;
                } else if (op[i] == 1) {
                    pre += cur * sign;
                    cur = number;
                    sign = 1;
                } else if (op[i] == 2) {
                    pre += cur * sign;
                    cur = number;
                    sign = -1;
                } else if (op[i] == 3) {
                    if (i + 1 < len - 1 && num[i + 1] == '0' && op[i + 1] == 0) {
                        pre = -10000000000;
                        break;
                    }
                    while(i + 1 < len - 1 && op[i + 1] == 0) {
                        i++;
                        number = number * 10 + num[i + 1] - '0';
                    }
                    cur *= number;
                }
            }
            // store
            pre += cur * sign;
            if (pre == target) {
                string tmp;
                tmp.push_back(num[0]);
                for (int i = 0; i < len - 1; i++) {
                    if (op[i] == 0) {
                        tmp.push_back(num[i + 1]);
                    } else if (op[i] == 1) {
                        tmp.push_back('+');
                        tmp.push_back(num[i + 1]);
                    } else if (op[i] == 2) {
                        tmp.push_back('-');
                        tmp.push_back(num[i + 1]);
                    } else if (op[i] == 3) {
                        tmp.push_back('*');
                        tmp.push_back(num[i + 1]);
                    }
                }
                ans.emplace_back(tmp);
            }

            // next
            op[len - 2]++;
            for (int i = len - 2; i > 0; i--) {
                if (op[i] > 3) {
                    op[i] -= 4;
                    op[i - 1]++;
                }
            }
        }
        return ans;
    }
};