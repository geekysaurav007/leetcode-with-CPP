class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0, r = 0, maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = -1;
        }
        while (r < s.length()) {
            if (mp[s[r]] != -1) {
               if(l<= mp[s[r]]){
                 l = mp[s[r]] + 1;
               }
            }
            mp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};