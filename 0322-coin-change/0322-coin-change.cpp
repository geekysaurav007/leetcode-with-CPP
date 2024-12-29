class Solution {
public:
    int solve(int index, vector<int>& nums, long long sum, int target,
              vector<vector<int>>& dp) {
        if (sum > target || index >= nums.size()) {
            return (sum == target) ? 0 : INT_MAX;
        }
        if (dp[index][sum] != -1)
            return dp[index][sum];
        long long take =
            solve(index, nums, sum + nums[index], target, dp);
        if (take != INT_MAX) {
            ++take;
        }
        long long not_take = solve(index + 1, nums, sum, target, dp);

        dp[index][sum] = min(take, not_take);
        return dp[index][sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        long long result = solve(0, coins, 0, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};