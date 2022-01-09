class Solution {
public:
   struct cmp {
       bool operator()(pair<int, int> x, pair<int, int> y) {
           return x.second > y.second;
       }
   };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto & num: nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> diffNums;
        for (auto & item: freq) {
            if (k) {
                diffNums.push(make_pair(item.first, item.second));
                k--;
            } else if (item.second > diffNums.top().second) {
                diffNums.pop();
                diffNums.push(make_pair(item.first, item.second));
            }
        }

        vector<int> ans;
        while (!diffNums.empty()) {
            ans.push_back(diffNums.top().first);
            diffNums.pop();
        }
        return ans;
    }
};