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
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);
        if (leftPath + rightPath > ans)
            ans = leftPath + rightPath;
        return (1 + max(leftPath, rightPath));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};