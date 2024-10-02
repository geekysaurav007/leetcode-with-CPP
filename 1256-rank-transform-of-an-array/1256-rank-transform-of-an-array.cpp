class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> ele(arr.begin(),arr.end());
        map<int,int> mp;
        int rank=1;
        vector<int> res;
        for(auto s:ele){
            mp[s]=rank++;
        }
        for (int i=0;i<arr.size();i++){
            res.push_back(mp[arr[i]]);
        }
        return res;
    }
};