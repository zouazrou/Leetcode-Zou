class Solution {
private:
    void dfs(TreeNode* root, int num, int& ans) {
        if (!root)
            return;
        if (!root->left && !root->right)
            ans += num * 10 + root->val;
        dfs(root->left, num * 10 + root->val, ans);
        dfs(root->right, num * 10 + root->val, ans);
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};