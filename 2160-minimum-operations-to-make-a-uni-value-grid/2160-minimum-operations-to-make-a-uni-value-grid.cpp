class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;
        for (const auto& row : grid) {
            for (int val : row) {
                ans.push_back(val);
            }
        }

        sort(ans.begin(), ans.end());

        for (int val : ans) {
            if (abs(val - ans[0]) % x != 0) {
                return -1;
            }
        }

        int median = ans[ans.size() / 2];
        int operations = 0;

        for (int val : ans) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};