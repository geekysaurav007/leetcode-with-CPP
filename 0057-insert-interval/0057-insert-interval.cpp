class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>>ans;
         if(interval.size()==0) { 
            ans.push_back(newInterval);
            return ans;
         }
        int i=0;
        while(i<interval.size()){
            if(interval[i][1]<newInterval[0]){
                ans.push_back(interval[i]);
              
            }else if(interval[i][1]>=newInterval[0] && interval[i][0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0],interval[i][0]);
                newInterval[1]=max(newInterval[1],interval[i][1]);
            }else if(interval[i][1]>newInterval[0] && !(interval[i][0]<=newInterval[1])){
                break;
            }
            i++;
        }
             ans.push_back(newInterval);
        for(int k=i;k<=interval.size()-1;k++){
            ans.push_back(interval[k]);
        }
        return ans;
    }
};