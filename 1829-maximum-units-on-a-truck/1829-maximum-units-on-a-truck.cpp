class Solution {
public:
      static bool compare(vector<int>& a, vector<int>& b) { return a[1] > b[1]; }
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        sort(box.begin(), box.end(), compare);
        int ans = 0;
        for (int i = 0; i < box.size(); i++) {
            if (box[i][0] < truckSize) {
                ans += (box[i][0] * box[i][1]);
                truckSize -= box[i][0];
            }else{
                // jitna truckSpace khaali ho utna lelo and uska units available multipli krdo
                ans+=(truckSize*box[i][1]);
                break;
            }
        }
        return ans;
    }
};