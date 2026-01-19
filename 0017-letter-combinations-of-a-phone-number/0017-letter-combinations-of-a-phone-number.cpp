class Solution {
private:
    map<char, string> phoneStr = 
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void solve(string rs, int idx, string& digits, vector<string>& ans) {
        if (idx == digits.size())
        {
            ans.push_back(rs);
            return ;
        }
        string& str = phoneStr[digits[idx]];
        for (int i = 0; i < (int)str.size(); i++)
            solve(rs + str[i], idx+1, digits, ans);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        solve("", 0, digits, ans);
        return ans;
    }
};