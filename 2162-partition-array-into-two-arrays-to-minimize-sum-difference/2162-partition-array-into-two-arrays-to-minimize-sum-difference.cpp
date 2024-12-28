class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1),
            right(n + 1); // left[i] stores all possible sums having i numbers
                          // taken into consideration, from the first half of
                          // nums (ie; index 0 to n-1, both included)
        for (int i = 0; i < pow(2, n); i++) {
            int ctr = 0;
            int a = 0, b = 0;
            for (int j = 0; j < n; j++) {
                if (1 << j & i) {
                    ctr++;
                    a += nums[j];
                    b += nums[n + j];
                }
            }
            left[ctr].push_back(a);
            right[ctr].push_back(b);
        }
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        int tot =
            left[n][0] + right[n][0]; // Take n elements from both halves, there
                                      // is only one sum in both these arrays
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (int l : left[i]) {
                int ind = lower_bound(right[n - i].begin(), right[n - i].end(),
                                      (ceil(tot / 2.0) - l)) -
                          right[n - i].begin();
                if (ind < right[n - i].size()) {
                    int a = l + right[n - i][ind];
                    ans = min(ans, 2 * a - tot);
                }
            }
        }
        return ans;
    }

}
;