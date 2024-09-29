class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0, r = 0, maxlen = 0, zero = 0;
        while (r < arr.size()) {
            if (arr[r] == 0)
                zero++;

            // if (zero <= k) {
            //     int len = r - l + 1;
            //     maxlen = max(maxlen, len);
            // }

            while (zero > k) {
                if (arr[l] == 0)
                    zero--;
                l++;
            }
            int len = r - l + 1;
                maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};