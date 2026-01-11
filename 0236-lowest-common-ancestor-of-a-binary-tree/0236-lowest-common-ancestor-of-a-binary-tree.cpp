/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*    DFS(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == q || root == p)
            return (root);
    
        TreeNode* left = DFS(root->left, p, q);
        TreeNode* right = DFS(root->right, p, q);
        if (left && right && left != right)
            return (root);
        if (left)
            return (left);
        return (right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p, q);
    }
};