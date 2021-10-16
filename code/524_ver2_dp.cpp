#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int lenS = s.length();
        vector<vector<int> > find(lenS, vector<int>(2));

        for (string i: dictionary) {
            int tip = 0, lenD = i.length();
            for (char c: s) {
                if (c == i[tip]) {
                    tip++;
                    if (tip == lenD) {
                        if (lenD > ans.length() || lenD == ans.length() && i < ans) {
                            ans = i; 
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};