/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    bool pathToVal(TreeNode *root, int targetValue, string& path)
    {
        if (!root)
            return false;
        if (root->val == targetValue)
            return true;

        path.push_back('L');
        if (pathToVal(root->left, targetValue, path))
            return (true);
        path.pop_back();


        path.push_back('R');
        if (pathToVal(root->right, targetValue, path))
            return (true);
        path.pop_back();
        return (false);
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        size_t n = 0;
        string path2Start;
        pathToVal(root, startValue, path2Start);
        string path2Dest;
        pathToVal(root, destValue, path2Dest);
        while (path2Start[n] == path2Dest[n])
            n++;
        return (string(path2Start.size()-n, 'U')+path2Dest.substr(n, path2Dest.size()-n));
    }
};