class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0, maxlen = 0;
        int zero = 0;
        while (r < arr.size()) {
            if (arr[r] == 0)
                zero++;
            if (zero <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            if (zero > k) {
                while (zero > k) {
                    if (arr[l] == 0)
                        zero--;
                    l++;
                }
            }
            r++;
        }
        return maxlen;
    }
};