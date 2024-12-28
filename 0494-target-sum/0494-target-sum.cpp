class Solution {
public:
    int helper(vector<int>& arr, int target, int idx, int sum) {
        if (idx >= arr.size())
            return sum == target ? 1 : 0;

        int subtract = helper(arr, target, idx + 1, sum - arr[idx]);
        int add = helper(arr, target, idx + 1, sum + arr[idx]);

        return subtract + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};