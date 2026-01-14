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
private:
    void updateAns(int& ans, int& a, int& b, int& c) {
        ans = max(ans, a);
        ans = max(ans, b);
        ans = max(ans, c);
        if (a != INT_MIN && b != INT_MIN && c != INT_MIN)
            ans = max(ans, a + b + c);
    }

    int dfs(TreeNode* root, int& ans) {
        if (!root)
            return INT_MIN;
        int leftPath = dfs(root->left, ans);
        int rightPath = dfs(root->right, ans);
        updateAns(ans, root->val, leftPath, rightPath);
        // Add current Node value to the Paths
        leftPath = (leftPath != INT_MIN) * leftPath + root->val;
        rightPath = (rightPath != INT_MIN) * rightPath + root->val;
        // Return larger Path
        // or Current Node value if was larger than both Paths
        return max(root->val, max(leftPath, rightPath));
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        ans = max(ans, dfs(root, ans));
        return ans;
    }
};