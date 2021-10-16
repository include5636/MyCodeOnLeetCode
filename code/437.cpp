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

class Solution {
public:
    int calc(vector<int>* st, int targetSum) {
        int ans = 0, sum = 0;
        for (int i = st->size() - 1; i >= 0; i--)
        {
            sum += st->at(i);
            if(sum == targetSum) ans++;
        }
        return ans;
    }

    int traverse(TreeNode* cur, int targetSum, vector<int>* st) {
        if(!cur) return 0;
        st->push_back(cur->val);
        int curAns = calc(st, targetSum) + traverse(cur->left, targetSum, st) 
                     + traverse(cur->right, targetSum, st);
        st->pop_back();
        return curAns;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> st;
        return traverse(root, targetSum, &st);
    }
};






 // long long
 // n == 0
// class Solution {
// public:
//     int calc(vector<long long>* st, long long targetSum) {
//         int size = st->size(), ans = 0;
//         long long sum = 0;
//         for (int i = size - 1; i >= 0; i--)
//         {
//             sum += st->at(i);
//             if(sum == targetSum)
//                 ans++;
//         }
//         return ans;
//     }

//     int traverse(TreeNode* cur, long long targetSum, vector<long long>* st) {
//         st->push_back(cur->val);
//         int curAns = calc(st, targetSum);
//         if(cur->left)
//             curAns += traverse(cur->left, targetSum, st);
//         if(cur->right)
//             curAns += traverse(cur->right, targetSum, st);
//         st->pop_back();
//         return curAns;
//     }

//     int pathSum(TreeNode* root, int targetSum) {
//         vector<long long> st;
//         return root ? traverse(root, targetSum, &st) : 0;
//     }
// };
