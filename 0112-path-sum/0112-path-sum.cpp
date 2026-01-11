#define RESET "\033[0m"
#define GREEN "\033[32m"
class Solution {
public:
    // BFS
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> currNode;
        TreeNode *left, *right;
        int currValue;

        if (!root)
            return false;
        q.push({root, targetSum - root->val});
        while (!q.empty()) {
            currNode = q.front();
            left = currNode.first->left;
            right = currNode.first->right;
            currValue = currNode.second;
            q.pop();
            if (currValue == 0 && !left && !right)
                return (true);
            if (left)
                q.push({left, currValue - left->val});
            if (right)
                q.push({right, currValue - right->val});
        }
        return false;
    }
    /*
    // **DFS**
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return (false);
        targetSum -= root->val;
        if (!root->left && !root->right)
            return (targetSum == 0);
        if  (hasPathSum(root->left, targetSum) == true
            || hasPathSum(root->right, targetSum) == true)
            return (true);
        return (false);
    }
    */
};