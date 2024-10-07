class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>ps;
        int cnt=0,ws=0;
        for(int i=0;i<nums.size();i++){
            ws+=nums[i];
            if(ws==goal){
                cnt++;
            }
            long long rem=ws-goal;
            if(ps.find(rem)!=ps.end()){
                cnt+=ps[rem];
            }
            ps[ws]++;
        }
        return cnt;
    }
};