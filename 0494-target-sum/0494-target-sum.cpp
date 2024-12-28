class Solution {
public:
    int helper(vector<int>& arr, int target, int idx, int sum,
               vector<vector<int>>& dp, int offset) {
        // Base case: when we've processed all elements
        if (idx == arr.size()) {
            return sum == target ? 1 : 0;
        }

        // Check if result is already memoized
        if (dp[idx][sum + offset] != -1) {
            return dp[idx][sum + offset];
        }

        // Recursive calls: add and subtract the current element
        int add = helper(arr, target, idx + 1, sum + arr[idx], dp, offset);
        int subtract = helper(arr, target, idx + 1, sum - arr[idx], dp, offset);

        // Memoize and return the result
        return dp[idx][sum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the target is not reachable, return 0
        if (abs(target) > totalSum)
            return 0;

        // Offset to handle negative sums
        int offset = totalSum;

        // DP table with size [nums.size()][2 * totalSum + 1]
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));

        return helper(nums, target, 0, 0, dp, offset);
    }
};