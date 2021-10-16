#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 // long long
 // n == 0
class Solution {
public:
    unordered_map<int, int> valSum;

    int traverse(TreeNode* root, int targetSum, long long curSum) {
        if(!root)
            return 0;

        curSum += root->val;
        int curAns = 0;
        if(valSum.find(curSum - targetSum) != valSum.end()) {
            curAns = valSum[curSum - targetSum];
        }

        valSum[curSum]++;
        curAns += traverse(root->left, targetSum, curSum) + traverse(root->right, targetSum, curSum);
        valSum[curSum]--;

        return curAns;
    }

    int pathSum(TreeNode* root, int targetSum) {
        valSum[0] = 1;
        return traverse(root, targetSum, 0);
    }
};
