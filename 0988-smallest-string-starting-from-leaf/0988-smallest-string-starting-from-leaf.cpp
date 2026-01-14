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
    const string& ft_min(const string& a, const string& b)
    {
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
        char c = static_cast<char>(root->val+'a');
        if (!root->left && !root->right)
            return c+s;
        return ft_min(dfs(root->left, c+s), dfs(root->right, c+s));
    }
    string smallestFromLeaf(TreeNode* root) { return dfs(root, ""); }
};
