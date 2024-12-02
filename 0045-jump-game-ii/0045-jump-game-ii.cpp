class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0; // No jumps needed if size is 1 or less
        if (nums.size() == 2) return 1; // Only one jump if size is 2

        int l = 1; // Left boundary of the current range
        int r = nums[0]; // Right boundary of the current range
        int step = 1; // Start with one jump
        int range = nums[0]; // Maximum range we can reach so far

        while (range < nums.size() - 1) { // While we haven't reached the last index
            for (int i = l; i <= r; ++i) {
                if (i >= nums.size() - 1) return ++step; // If we reach the end
                range = max(range, i + nums[i]); // Update the maximum range
            }
            step++; // Increment step count
            l = r; // Move left boundary to the previous right boundary
            r = range; // Update right boundary to the new maximum range
        }

        return step; // Return the total number of steps
    }
};