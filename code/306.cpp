#include<bits/stdc++.h>
using namespace std;

/**
 * dfs，枚举所有情况并验证
 * 细节比较多
 * 需要用高精度，我用string表示数字，为了方便进行相加，将字符串倒过来存储，即最低位保存在s[0]
 */

class Solution {
public:
    bool equal(string ppre, string pre, string cur) {
        int lenPP = ppre.size(), lenP = pre.size();
        string sum = "";
        int tmp = 0;
        for (int i = 0; i < lenPP || i < lenP; i++) {
            if (tmp) {
                tmp = 0;
            } else {
                sum = sum + '0';
            }
            if (i >= lenPP) {
                sum[i] += pre[i] - '0';
            } else if (i >= lenP) {
                sum[i] += ppre[i] - '0';
            } else {
                sum[i] += pre[i] - '0' + ppre[i] - '0';
            }
            if (sum[i] - '0' > 9) {
                sum = sum + '0';
                tmp = 1;
                sum[i + 1] += (sum[i] - '0') / 10;
                sum[i] -= 10;
            }
        }
        return sum.compare(cur) == 0;
    }

    bool dfs(string num, string ppre, string pre) {
        int lenN = num.size();
        string cur = "";
        for (int i = 0; i < lenN; i++) {
            if (num[0] == '0' && i > 0) {
                return false;
            }
            cur = num[i] + cur;
            if (equal(ppre, pre, cur)) {
                if (i == lenN - 1) {
                    return true;
                }
                ppre = pre;
                pre = cur;
                if (dfs(num.substr(i + 1, lenN), ppre, pre)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int lenN = num.size();
        if (lenN < 3) {
            return false;
        }
        string ppre = "";
        for (int i = 1; i <= lenN / 2; i++) {
            if (num[0] == '0' && i > 1) {
                return false;
            }
            ppre = num[i - 1] + ppre;
            string pre = "";
            for (int j = 1; j <= lenN / 2; j++) {
                if (num[i] == '0' && j > 1) {
                    break;
                }
                pre = num[i + j - 1] + pre;
                if (dfs(num.substr(i + j, lenN), ppre, pre)) {
                    return true;
                }
            }
        }
        return false;
    }
};