class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         for (int k = j + 1; k < nums.size(); k++) {
        //             long long pre =  long((nums[i] - nums[j]) * nums[k]);
        //             maxi = max(maxi, pre);
        //         }
        //     }
        // }
        // return maxi;
        vector<int> l(nums.size(), 0), r(nums.size(), 0);
        int n = nums.size();
        for (int i = 0; i < nums.size()-1; i++) {
            l[i + 1] = max(l[i], nums[i]);
            r[n - 2 - i] = max(r[n - i - 1], nums[n - i - 1]);
        }
        for (int j = 1; j < nums.size() - 1; j++) {
            maxi = max(maxi, (long long)(l[j] - nums[j]) * r[j]);
        }
        return maxi;
    }
};