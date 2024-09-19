class Solution {
public:
    void solve(int index, int n, int s, int target, vector<vector<int>>& ans,
               vector<int>& temp, vector<int>& nums) {
                if(s>target) return;
        if (s == target) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < n; i++) {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            s += nums[i];
            temp.push_back(nums[i]);
            solve(i + 1, n, s, target, ans, temp, nums);
            s -= nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s = 0;
        solve(0, n, s, target, ans, ds, nums);
        return ans;
    }
};