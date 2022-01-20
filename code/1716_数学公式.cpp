#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        return (28 + 28 + 7 * (n / 7 - 1)) * (n / 7) / 2 + (1 + (n - (n / 7) * 7)) * (n - (n / 7) * 7) / 2 + (n - (n / 7) * 7) * (n / 7);
    }
};