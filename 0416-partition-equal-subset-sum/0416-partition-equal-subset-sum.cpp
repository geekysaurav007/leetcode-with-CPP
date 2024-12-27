class Solution {
public:
    bool solve(int index, vector<int>& nums, int sum, int target,vector<vector<int>>&dp) {
        if (sum == target) {
            return true;
        }
        if (index == nums.size() || sum > target) {
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        sum += nums[index];
        int pick = solve(index + 1, nums, sum, target,dp);
        sum -= nums[index];
        int non_pick = solve(index + 1, nums, sum, target,dp);
        dp[index][sum]= pick || non_pick;
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        vector<vector<int>>dp(nums.size(), vector<int>(sum + 1, -1));
        if (sum % 2 != 0)
            return false;
        return solve(0, nums, 0, sum / 2,dp);
    }
};