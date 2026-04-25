class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        int j;
        for (int i = 1; i < strs.size(); i++)
        {
            j = 0;
            while (strs[i][j] && ans[j] && ans[j] == strs[i][j])
                j++;
            ans = ans.substr(0, j);
            cerr << ans << endl;
        }
        return ans;
    }
};