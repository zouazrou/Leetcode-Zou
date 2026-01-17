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

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        do{
            ans.push_back(nums);
            ft_next_permutation(nums);
        }
        while (ans[0] != nums);
        return ans;
    }
};