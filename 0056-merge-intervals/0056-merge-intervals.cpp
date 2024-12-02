class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merge;
         sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
       
        for (auto it : intervals) {
            if (it[0] <= temp[1]) {
                temp[1] = max(temp[1], it[1]);
            } else {
             
                merge.push_back(temp);
                   temp = it;
                
            }
        }
        merge.push_back(temp);
        return merge;
    }
};