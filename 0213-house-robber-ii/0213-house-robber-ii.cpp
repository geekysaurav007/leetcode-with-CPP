class Solution {
public:
    int dp[101];
    int solve(int index, vector<int>& nums, int n) {
        if (index > n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int pick = nums[index] + solve(index + 2, nums, n);
        int non_pick = 0 + solve(index + 1, nums, n);
        dp[index] = max(pick, non_pick);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        memset(dp, -1, sizeof(dp));
        int pick_zero = solve(0, nums, n - 2);
        memset(dp, -1, sizeof(dp));
        int pick_one = solve(1, nums, n - 1);
        return max(pick_zero, pick_one);
    }
};