class Solution {
public:
    void combo(int index, vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            combo(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        combo(0, nums, temp, ans);
        return ans;
    }
};