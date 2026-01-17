class Solution {
private:
    void solve(vector<int> perm, size_t sz, unordered_map<int, int> cnt,
               vector<vector<int>>& ans) {
        if (perm.size() == sz)
        {
            ans.push_back(perm);
            return ;
        }
        for (auto& [num, count] : cnt)
        {
            if (!count)
                continue;
            count--;
            perm.push_back(num);
            solve(perm, sz, cnt, ans);
            count++;
            perm.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> cnt;
        size_t sz = nums.size();
        for (size_t i = 0; i < sz; i++)
            cnt[nums[i]]++;
        solve(vector<int>(), sz, cnt, ans);
        return ans;
    }
};