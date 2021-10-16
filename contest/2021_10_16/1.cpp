#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0, size = seats.size();
        for (int i = 0; i < size; i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};