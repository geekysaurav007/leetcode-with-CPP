class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), sum = 0, cnt = 0;
        while (r < n) {
            sum += (nums[r] % 2);

            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            if (sum <= k) {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        int x = helper(arr, k);
        int y = helper(arr, k - 1);
        return x - y;
    }
};