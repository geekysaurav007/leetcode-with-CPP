class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxlen = 0;
        int n = s.size();
       
        for (int i = 0; i < n; i++) {
            mp[s[i]] = -1;
        }
        while (r < n) {
            if (mp[s[r]] != -1) {
                if (mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(len, maxlen);
            mp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};