#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
            stack<long long> st;
            bool err = 0;
            st.push(num[0] - '0');
            for (int i = 0; i < len - 1; i++) {
                long long number = num[i + 1] - '0';
                if (op[i] == 0) {
                    long long pre = st.top();
                    if (pre == 0) {
                        err = 1;
                        break;
                    }
                    st.push(pre * 10 + number);
                } else if (op[i] == 1) {
                    
                } else if (op[i] == 2) {

                } else if (op[i] == 3) {

                }
            }

            // store

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