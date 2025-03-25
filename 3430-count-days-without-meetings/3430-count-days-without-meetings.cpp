class Solution {
public:
    int countDays(int days, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        int cnt = 0;
        for (auto nums : ans) {
            int a = nums[0];
            int b = nums[1];
            cnt += b - a + 1;
        }
        return days-cnt;
    }
};