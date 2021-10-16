#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candy(size, 1);
        for (int i = 1; i < size; i++)
            if(ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        for (int i = size; i > 0; i--)
            if(ratings[i-1] > ratings[i])
                candy[i-1] = max(candy[i-1], candy[i] + 1);
        return accumulate(candy.begin(), candy.end(), 0);
    }
};