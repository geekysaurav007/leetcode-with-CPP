class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int index = -1;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {

            if (mp[nums[i]]) {
                index = i;
                break;
            } else {
                mp[nums[i]]++;
            }
        }
        return index != -1 ? (index / 3) + 1 : index + 1;
    }
};