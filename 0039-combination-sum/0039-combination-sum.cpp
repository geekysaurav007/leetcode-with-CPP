class Solution {
public:
    void combo(int index, vector<int>& nums, int target, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (index == nums.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[index] <= target) {
            temp.push_back(nums[index]);
            combo(index, nums, target - nums[index], temp, ans);
            temp.pop_back();
        }
        combo(index + 1, nums, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        combo(0, nums, target, temp, ans);
        return ans;
    }
};