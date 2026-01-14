class Solution {
private:
    // int dfs(TreeNode* root, int num) {
    //     if (!root)
    //         return 0;
    //     if (!root->left && !root->right)
    //         return num * 10 + root->val;
    //     return dfs(root->left, num * 10 + root->val)
    //           +dfs(root->right, num * 10 + root->val);
    // }
    int bfs(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> curr;
        q.push({root, root->val});
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (!curr.first->left && !curr.first->right)
                ans += curr.second;
            if (curr.first->left)
                q.push({curr.first->left,
                        curr.first->left->val + 10 * curr.second});
            if (curr.first->right)
                q.push({curr.first->right,
                        curr.first->right->val + 10 * curr.second});
        }
        return ans;
    }

public:
    int sumNumbers(TreeNode* root) {
        // return dfs(root, 0);
        return bfs(root);
    }
};