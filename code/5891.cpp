#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int sum = mean * (size + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if(sum < n || 6 * n < sum)
            return vector<int>();
        vector<int> ans;
        sum -= n;
        for (int i = 0; i < n; i++)
        {
            if(sum >=5)
            {
                ans.push_back(6);
                sum -= 5;
            }
            else if(sum)
            {
                ans.push_back(sum + 1);
                sum = 0;
            }
            else    
                ans.push_back(1);
        }
        return ans;
    }
};

int main()
{

}