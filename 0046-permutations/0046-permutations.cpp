class Solution {
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

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int fc[] = {0, 1, 2, 6, 24, 120, 720};
        int nump = fc[nums.size()];
        vector<vector<int>> ans(nump);
        ans[0] = nums;
        for (int i = 1; i < nump; i++) {
            ft_next_permutation(nums);
            ans[i] = nums;
        }
        return ans;
    }
};