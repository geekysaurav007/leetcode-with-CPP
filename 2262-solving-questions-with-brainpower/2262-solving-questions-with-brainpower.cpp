class Solution {
public:
    long long solve(int index, vector<vector<int>>& arr,
                    vector<long long>& dp) {
        if (index >= arr.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        long long take = arr[index][0] + solve(index + arr[index][1] + 1, arr, dp);
        long long not_take = 0 + solve(index + 1, arr, dp);
        return dp[index] = max(take, not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() + 1, -1);
        return solve(0, questions, dp);
    }
};