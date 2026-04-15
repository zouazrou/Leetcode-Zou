class NumArray {
private:
    vector<int> n;
public:
    NumArray(vector<int>& nums) {
        n = nums;
        for (int i = 1; i < n.size(); i++)
        {
            n[i] += n[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return (n[right]);
        return (n[right]-n[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */