class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, sum = 0;
        while (r < n) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            if (sum <= goal) {
                cnt += r - l + 1;
                r++;
            }
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = helper(nums, goal);
        int right = helper(nums, goal - 1);
        return left - right;
    }
};