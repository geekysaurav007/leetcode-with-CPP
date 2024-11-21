class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>s;
        int i=0,j=0;
        long long sum=0;
        long long maxsum=0;
        while(j<nums.size()){
            // nums[j] already in set toh start se nikalo
            while(s.count(nums[j])){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j]);
            if(j-i+1==k){ // check agar curr lenth ==k hai toh left se nikalo
                maxsum=max(sum,maxsum);
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxsum;
    }
};