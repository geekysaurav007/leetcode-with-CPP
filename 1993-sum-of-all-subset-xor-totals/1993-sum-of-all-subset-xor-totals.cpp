class Solution {
public:
    int totalSum = 0;
     void solve(int index, vector<int>& nums, int sum) {
        if (index >= nums.size()) {
            totalSum += sum;
            return;
        }
        solve(index + 1, nums, nums[index] ^ sum);
        solve(index + 1, nums, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return totalSum;
    }
};