class Solution {
public:
    string solve(string ans, int n, int& k) {
        if (ans.size() == n) {
            k--;
            return (k ? "" : ans);
        }
        string res;
        for (int num = 1; num <= n; num++) {
            if (ans.find(char(num + '0')) != string::npos)
                continue;
            res = solve(ans + char(num + '0'), n, k);
            if (!res.empty())
                return res;
        }
        return "";
    }
    string getPermutation(int n, int k) { return solve("", n, k); }
};