class Solution {
public:
    int solve(int index, vector<int>& nums, int target, int sum,
              vector<vector<int>>& dp) {
        if (sum == target)
            return 1;
        if (sum > target || index >= nums.size())
            return 0;
        if (dp[index][sum] != -1)
            return dp[index][sum];
        int take = solve(index, nums, target, sum + nums[index], dp);
        int not_take = solve(index + 1, nums, target, sum, dp);
        return dp[index][sum] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, coins, amount, 0, dp);
    }
};