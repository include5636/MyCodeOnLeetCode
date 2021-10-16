#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y) {
        if (x[0] != y[0]) {
            return x[0] < y[0];
        } else {
            return x[1] > y[1];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int size = people.size(), cnt;
        vector<vector<int> > ans(size);
        for (int i = 0; i < size; i++) {
            cnt = people[i][1] + 1;
            for (int j = 0; j < size; j++) {
                if (ans[j].empty()) {
                    cnt--;
                    if (!cnt) {
                        ans[j] = people[i];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};