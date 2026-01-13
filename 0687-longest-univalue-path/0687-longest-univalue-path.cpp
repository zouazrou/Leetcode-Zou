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
    int ans;

    int dfs(TreeNode* root, int prvVal) {
        if (!root)
            return 0;
        int leftPath = dfs(root->left, root->val);
        int rightPath = dfs(root->right, root->val);
        ans = max(leftPath + rightPath, ans);
        if (root->val == prvVal)
            return (1 + max(leftPath, rightPath));
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root, 1001);
        return (ans);
    }
};