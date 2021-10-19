#include<bits/stdc++.h>
using namespace std;

int calc(vector<int>& nums, int maxOr, int cur, int pos) {
    int size = nums.size(), sum = 0;
    for (int i = pos; i < size; i++) {
        int curOr = cur | nums[i];
        if (curOr == maxOr) {
            sum += pow(2, size - i - 1);
        } else if (i != size - 1) {
            sum += calc(nums, maxOr, curOr, i + 1);
        }
    }
    return sum;
}

int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;
    for(int i: nums) {
        maxOr |= i;
    }
    return calc(nums, maxOr, 0, 0);
}

int main() {
    vector<int> tmp = {3, 2, 1, 5};
    printf("%d", countMaxOrSubsets(tmp));
    return 0;
}
