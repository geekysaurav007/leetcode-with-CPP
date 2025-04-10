class Solution {
public:
    int totalSum = 0;
    int solve(int index, vector<int>& nums, int sum) {
        if (index >= nums.size()) {
            return sum;
        }
        int take = solve(index + 1, nums, nums[index] ^ sum);
        int skip = solve(index + 1, nums, sum);
        return take + skip;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
        // return totalSum;
    }
};