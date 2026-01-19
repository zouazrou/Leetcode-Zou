class Solution {
public:
    void bt(string res, int opn, int cls, vector<string>& ans) {
        if (!opn && !cls) {
            ans.push_back(res);
            return;
        }
        if (opn) {
            bt(res + '(', opn - 1, cls, ans)    ;
        }
        if (cls && cls != opn) {
            bt(res + ')', opn, cls - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        bt("", n, n, ans);
        return (ans);
    }
};