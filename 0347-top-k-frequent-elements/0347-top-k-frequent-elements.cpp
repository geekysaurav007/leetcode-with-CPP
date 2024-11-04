
class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<p, vector<p>,
                       greater<p>>
            pq;
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }
        for (const auto& it : mp) {
            pq.push({it.second, it.first}); // {frequency, number}
            if (pq.size() > k) {
                pq.pop(); // Maintain only the top k elements
            }
        }

        // Collect the top k elements
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second); // Get the number
            pq.pop();
        }
        return ans;
    }
};