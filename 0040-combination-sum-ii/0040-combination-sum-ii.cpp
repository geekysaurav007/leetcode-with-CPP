class Solution {
public:
    void solve(int index, int target, vector<vector<int>>& ans, vector<int>& ds,
               vector<int>& nums) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i>index && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            solve(i + 1, target - nums[i], ans, ds, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, target, ans, ds, nums);
        return ans;
    }
};