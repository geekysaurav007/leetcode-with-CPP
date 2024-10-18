class Solution {
public:
    int count = 0;
    int maxor = 0;
    void solve(vector<int>& nums, int curr, int i) {
        if (i == nums.size()) {
            if (curr == maxor) {
                count++;
            }
            return;
        }
        solve(nums, curr | nums[i], i + 1);
        solve(nums, curr, i + 1);
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int curr = 0;
        for (auto it : nums) {
            maxor = maxor | it;
        }

        solve(nums, curr, 0);
        return count;
    }
};