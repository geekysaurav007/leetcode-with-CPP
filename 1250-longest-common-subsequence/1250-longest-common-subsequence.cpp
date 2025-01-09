class Solution {
public:
    int m, n;
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (s1[i] == s2[j]) {
            return 1 + solve(s1, s2, i + 1, j + 1, dp);
        }
        int left_choro = solve(s1, s2, i, j + 1, dp);
        int right_choro = solve(s1, s2, i + 1, j, dp);
        return dp[i][j]=max(left_choro, right_choro);
    }
    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};