#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int day = 0, week = 0, money = 0;
        for (int i = 1; i <= n; i++) {
            day++;
            if (day > 7) {
                day = 1;
                week++;
            }
            money += day + week;
        }
        return money;
    }
};