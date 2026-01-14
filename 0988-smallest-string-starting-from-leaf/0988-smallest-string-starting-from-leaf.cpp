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
    const string& ft_min(const string& a, const string& b) {
        if (a.empty())
            return (b);
        if (b.empty())
            return (a);
        return min(a, b);
    }

public:
    string dfs(TreeNode* root, string s) {
        if (!root)
            return "";
        s = static_cast<char>(root->val + 'a') + s; 
        if (!root->left && !root->right)
            return s;
        return ft_min(dfs(root->left, s), dfs(root->right, s));
    }
    string smallestFromLeaf(TreeNode* root) { return dfs(root, ""); }
};
