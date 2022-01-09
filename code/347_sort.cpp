class Solution {
public:
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        return x.second > y.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto & num: nums) {
            freq[num]++;
        }

        vector<pair<int, int> > diffNums;
        for (auto & item: freq) {
            diffNums.push_back(make_pair(item.first, item.second));
        }
        
        sort(diffNums.begin(), diffNums.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; i ++) {
            ans.push_back(diffNums[i].first);
        }
        return ans;
    }
};