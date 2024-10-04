class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int mid1 = (n - 1) / 2;
        int mid2 = mid1 + 1; // starting of 2nd array
        int j = n - 1;       // second array index
        int i = 0;
        vector<pair<long, long>> p;
        vector<long> s;
        while (i <= mid1) {
            p.push_back(make_pair(a[i], a[j]));
            s.push_back(a[i] + a[j]);
            i++;
            j--;
        }
        for (int k = 1; k < s.size(); k++) {
            if (s[k] != s[k - 1])
                return -1;
        }
        long long sum = 0;
        for (auto s : p) {
            sum += s.first * s.second;
        }
        return sum;
    }
};