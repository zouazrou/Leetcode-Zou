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
    void DFS(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;
        targetSum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == 0)
            ans.push_back(path);
        else {
            DFS(root->left, targetSum, path, ans);
            DFS(root->right, targetSum, path, ans);
        }
        path.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        DFS(root, targetSum, path, ans);
        // BFS(root, targetSum, ans);
        return (ans);
    }
    /*
    // **BFS**
    void BFS(TreeNode *root, int& targetSum, vector<vector<int>>& ans)
    {
        queue< pair<TreeNode *, pair<vector<int>, int>> > q;

        if (root == nullptr)
            return;
        q.push({root, {{root->val}, root->val}});
        // *   currNode, vec currPath, currSum
        while (!q.empty())
        {
            TreeNode& currNode = *q.front().first;
            vector<int>& currPath = q.front().second.first;
            int& currSum = q.front().second.second;
            if (!currNode.left && !currNode.right && currSum == targetSum)
                ans.push_back(currPath);
            if (currNode.left)
            {
                currPath.push_back(currNode.left->val);
                q.push({currNode.left, {currPath, currSum+currNode.left->val}});
                currPath.pop_back();
            }
            if (currNode.right)
            {
                currPath.push_back(currNode.right->val);
                q.push({currNode.right, {currPath, currSum+currNode.right->val}});
                currPath.pop_back();
            }
            q.pop();
        }
        return;
    }
    */
};