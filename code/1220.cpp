#include<bits/stdc++.h>
using namespace std;

/*
main idea: 找出对应关系
    a - e i u
    e - a i 
    i - e o
    o - i 
    u - i o
    之后简单dp，num[a] = num[e] + num[i] + num[u], so forth.
    也可以用矩阵快速幂，但我还不会
*/

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        /* a e i o u --- 0 1 2 3 4 */
        long long num[5] = {0}, preNum[5] = {1, 1, 1, 1, 1};
        while (--n) {
            num[0] = preNum[1] + preNum[2] + preNum[4];
            num[1] = preNum[0] + preNum[2];
            num[2] = preNum[1] + preNum[3];
            num[3] = preNum[2];
            num[4] = preNum[2] + preNum[3];
            for (int i = 0; i < 5; i++) {
                preNum[i] = num[i] % MOD;
            }
        }
        long long cnt = 0;
        for (int i = 0; i < 5; i++) {
            cnt += preNum[i];
        }
        return (int)(cnt % MOD);
    }
};