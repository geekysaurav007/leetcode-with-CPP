class Solution {
public:
    void createPrefix(vector<int>& height, vector<int>& prefix) {
        prefix[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
    }
    void createSuffix(vector<int>& height, vector<int>& suffix) {
        int n = height.size();
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> prefix(n);
        vector<int> suffix(n);
        createPrefix(height,prefix);
        createSuffix(height,suffix);
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            trappedWater += min(prefix[i], suffix[i]) - height[i];
        }

        return trappedWater;
        ;
    }
};