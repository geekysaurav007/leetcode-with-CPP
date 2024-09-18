class Solution {
public:
    void combo(int index, vector<int>& nums, int &sum, int target,
               vector<int>& ds, vector<vector<int>>& ans) {
        int n = nums.size();
        if(sum>target) return;
        if (index >= n) {
            if (sum == target) {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(nums[index]);
        sum += nums[index];
        combo(index , nums, sum, target, ds, ans);
        sum -= nums[index];
        ds.pop_back();
        combo(index + 1, nums, sum, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0 ;
        combo(0, nums, sum, target, temp, ans);
        return ans;
    }
};