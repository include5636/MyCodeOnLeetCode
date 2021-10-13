#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int> > f(len1+1);
        for (int i = 1; i <= len1; i++)
            f[i].resize(len2+1);
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
                if(word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                else
                    f[i][j] = max(f[i][j-1], f[i-1][j]);
        return len1 + len2 - (f[len1][len2] << 1)
    }
};