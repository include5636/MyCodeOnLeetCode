#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size(), cnt = 0;
        if (size == 1 && flowerbed[0] == 0)
            cnt++;
        if (size > 1) {
            if (!(flowerbed[0] | flowerbed[1])) {
                cnt++;
                flowerbed[0] = 1;
            }
            if (!(flowerbed[size - 1] | flowerbed[size - 2])) {
                cnt++;
                flowerbed[size - 1] = 1;
            }
        }
        if(cnt >= n)
            return 1;
        for (int i = 1; i < size - 1; i++) 
            if (!(flowerbed[i - 1] | flowerbed[i + 1] | flowerbed[i])) {
                cnt++;
                if(cnt == n)
                    return 1;
                flowerbed[i] = 1;
            }
        return 0;
    }
};