class Solution {
public:
    int minSubarray(vector<int>& v, int p) {
        long long sum = accumulate(v.begin(), v.end(), 0LL) % p;
        if (sum == 0)
            return 0; // Already divisible by p

        unordered_map<long long, int> mp;
        mp[0] = -1; // Handle case when the subarray starts from index 0
        long long current_sum = 0;
        int minLen = v.size();

        for (int i = 0; i < v.size(); i++) {
            current_sum = (current_sum + v[i]) % p;
            long long target_rem = (current_sum - sum + p) % p;

            if (mp.find(target_rem) != mp.end()) {
                minLen = min(minLen, i - mp[target_rem]);
            }
            mp[current_sum] = i;
        }

        return minLen == v.size() ? -1 : minLen;
    }
};
