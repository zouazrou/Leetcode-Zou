class Solution {
private:
    int dfs(TreeNode* root, int num) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return num * 10 + root->val;
        return dfs(root->left, num * 10 + root->val)
              +dfs(root->right, num * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};