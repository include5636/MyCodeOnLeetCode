#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, bool> exist;
        int num = 0, size = candyType.size();
        for(auto & candy: candyType) {
            if(!exist[candy]) {
                num++;
                exist[candy] = true;
            }
        }
        if (num > (size >> 1)) {
            return (size >> 1);
        } else {
            return num;
        }
    }
};