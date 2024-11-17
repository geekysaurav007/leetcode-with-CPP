class Solution {
public:
    int solve(int k, vector<int>& nums) {
        int csum = 0, l = 0, r = 0, minl = INT_MAX;
        while (r < nums.size()) {
            csum += nums[r];
            while (csum >= k) {
                minl = min(minl, r - l + 1);
                csum -= nums[l];
                l++;
            }
            r++;
        }
        return minl==INT_MAX?0:minl;
    }
    int minSubArrayLen(int k, vector<int>& nums) {
        return solve(k, nums) ;
    }
};