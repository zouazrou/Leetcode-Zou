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
class Solution {
public:
    void DFS(TreeNode* root, int targetSum, deque<long long> nums, int& ans) {
        if (!root)
            return;
        long long sum;
        nums.push_back(root->val);
        deque<long long> temp = nums;
        while (!temp.empty()) {
            sum = accumulate(temp.begin(), temp.end(), 0l);
            if (sum == targetSum)
                ans++;
            temp.pop_front();
        }
        if (root->left)
            DFS(root->left, targetSum, nums, ans);
        if (root->right)
            DFS(root->right, targetSum, nums, ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        deque<long long> v;
        DFS(root, targetSum, v, ans);
        return (ans);
    }
};