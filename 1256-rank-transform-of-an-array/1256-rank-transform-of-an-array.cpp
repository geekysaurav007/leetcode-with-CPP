class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }
        int rank = 1;
        int prev = INT_MAX;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (prev == p.first) {
                ans[p.second] = rank-1;
                prev = p.first;
            } else {
                ans[p.second] = rank++;
                prev = p.first;
            }
        }
        return ans;
    }
};