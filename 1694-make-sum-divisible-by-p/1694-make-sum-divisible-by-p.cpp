class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total_sum = 0, n = nums.size();
        for (int num : nums)
            total_sum = (total_sum + num) % p;

        if (total_sum == 0)
            return 0; // Already divisible by p

        unordered_map<int, int> prefix_mod = {{0, -1}}; // Remainder map
        int current_sum = 0, min_len = n;

        for (int i = 0; i < n; ++i) {
            current_sum = (current_sum + nums[i]) % p;
            int target_rem = (current_sum - total_sum + p) % p;

            if (prefix_mod.count(target_rem))
                min_len = min(min_len, i - prefix_mod[target_rem]);

            prefix_mod[current_sum] = i;
        }

        return min_len == n ? -1 : min_len;
    }
};
