class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int pick = nums[index] + solve(index + 2, nums,dp);
        int non_pick = solve(index + 1, nums,dp);
        dp[index] = max(pick, non_pick);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};