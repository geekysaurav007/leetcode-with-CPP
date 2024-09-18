class Solution {
public:
    void combo(int index,vector<vector<int>> &ans,  vector<int> &temp,vector<int>& nums){
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        combo(index + 1, ans, temp, nums);
        temp.pop_back();
        combo(index + 1, ans, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        combo(0, ans, temp, nums);
        return ans;
    }
};