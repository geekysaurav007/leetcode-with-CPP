class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1){
                ans=nums[i];
                break;
            }
            
        }
        return ans;
    }
};