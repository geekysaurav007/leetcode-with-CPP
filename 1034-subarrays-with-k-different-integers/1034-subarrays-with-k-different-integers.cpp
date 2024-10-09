class Solution {
public:
    int helper(vector<int>& arr, int k) {
        int l = 0, r = 0, n = arr.size();
        long long cnt = 0;
        unordered_map<int, int> mp;
        while (r < n) {
            mp[arr[r]]++;
            while (mp.size() > k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) {
                    mp.erase(arr[l]);
                }
                l++;
            }

           if(mp.size()<=k){
             cnt += r - l + 1;
           }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = helper(nums, k);
        int y = helper(nums, k - 1);
        return x - y;
    }
};