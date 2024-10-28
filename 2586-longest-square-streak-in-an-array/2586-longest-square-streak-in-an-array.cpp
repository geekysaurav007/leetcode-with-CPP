class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxlen = 0;

        for (int num : nums) {
            int length = 1;
            long long current = num;

            // Check if we can find a streak where each element is the square of
            // the previous
            while (numSet.count(current * current)) {
                current = current * current;
                length++;
            }

            maxlen = max(maxlen, length);
        }

        return maxlen > 1 ? maxlen : -1;
    }
};