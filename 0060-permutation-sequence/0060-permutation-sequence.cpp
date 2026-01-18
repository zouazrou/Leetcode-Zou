class Solution {
private:
    void ft_next_permutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        auto i = nums.end();
        i--;
        while (1) {
            auto j = i;
            i--;
            if (*i < *j) {
                auto k = nums.end();
                k--;
                while (*i >= *k)
                    k--;
                swap(*i, *k);
                reverse(j, nums.end());
                return;
            }
            if (i == nums.begin()) {
                reverse(i, nums.end());
                return;
            }
        }
    }
    // **USING DFS**
    // string solve(string ans, int n, int& k) {
    //     if (ans.size() == n) {
    //         k--;
    //         return (k ? "" : ans);
    //     }
    //     string res;
    //     for (int num = 1; num <= n; num++) {
    //         if (ans.find(char(num + '0')) != string::npos)
    //             continue;
    //         res = solve(ans + char(num + '0'), n, k);
    //         if (!res.empty())
    //             return res;
    //     }
    //     return "";
    // }
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        while (--k) {
            ft_next_permutation(nums);
        }
        string ans;
        for (int i = 0; i < n; i++)
            ans += char(nums[i] + '0');
        return ans;
        // return solve("", n, k);
    }
};