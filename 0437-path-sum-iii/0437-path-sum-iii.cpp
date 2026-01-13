/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

typedef long long ll;

class Solution {
public:
    void DFS(TreeNode* root, ll targetSum, unordered_map<ll, ll> Map, ll prvSum,
             int& ans) {
        if (!root)
            return;
        ll currSum = prvSum + root->val;
        ll Needed = currSum - targetSum;

        if (Map.find(Needed) != Map.end())
            ans += Map[Needed];

        if (Map.find(currSum) != Map.end())
            Map[currSum]++;
        else
            Map[currSum] = 1;
        DFS(root->left, targetSum, Map, currSum, ans);
        DFS(root->right, targetSum, Map, currSum, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<ll, ll> Map;
        Map[0] = 1;
        DFS(root, targetSum, Map, 0, ans);
        return (ans);
    }
};