class compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        unordered_map<int, int> mp;
        if (nums.size() == 1)
            return {nums[0]};
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