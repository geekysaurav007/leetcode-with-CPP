class Solution {
public:
    long long maxKelements(vector<int>& arr, int k) {
        priority_queue<long long> pq;
        for (int num : arr) {
            pq.push(num);
        }
        long long score = 0;

        for (int i = 0; i < k; ++i) {
            long long maxVal = pq.top();
            pq.pop();
            score += maxVal;
            pq.push((maxVal + 2) / 3);  // Using (maxVal + 2) / 3 to simulate ceil
        }
        
        return score;
    }
};