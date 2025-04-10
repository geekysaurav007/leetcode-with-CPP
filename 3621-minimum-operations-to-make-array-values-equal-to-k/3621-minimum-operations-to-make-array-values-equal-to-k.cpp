class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> visited;
        for (int num : nums) {
            if (num < k) return -1;
            if (num > k) visited.insert(num);
        }
        return visited.size();
    }
};